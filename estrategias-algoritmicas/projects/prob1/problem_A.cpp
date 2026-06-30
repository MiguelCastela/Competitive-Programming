#include <bits/stdc++.h> //remover em mac
#include <math.h> 
using namespace std;

class Outpost {
    public:
    int n;
    int x, y;
    vector<pair<int,int>> freeSpaces;
    
    Outpost(int n, int x_coord, int y_coord) : n(n), x(x_coord), y(y_coord) {}
};

class Wall {
    public:
    int x, y;
    
    Wall(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
};

class EmptySpace {
    public:
    int x, y;
    
    EmptySpace(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
};

class Turret {
    public:
    int x, y;
    
    Turret(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
};


int T, r, c;
vector<vector<char>> grid;
vector<Outpost> outposts;
vector<Wall> walls;
vector<EmptySpace> empties;
vector<Turret> turrets;
vector<EmptySpace> coverage;


vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
bool check_direction(int row,int col, int n){
    
    row += dir[n].first;
    col += dir[n].second;

    // Out of bounds 👍
    if (row >= r || row < 0 || col >= c || col < 0){
        return true;
    }   
    // A turret is found 👎
    if (grid[row][col] == 'x'){
        return false;
    }

    // Continue
    if (grid[row][col] == '.'){
        return check_direction(row,col,n);
    }
    // Any other object is found that blocks that direction and we can skip the rest of the checks 👍
    return true;
}
bool check_directions(int row, int col){
    return check_direction(row,col,0) &&
            check_direction(row,col,1) &&
            check_direction(row,col,2) &&
            check_direction(row,col,3);
}

bool check_for_zeros(int row, int col){
    for (auto n : dir){
        int newRow = row + n.first;
        int newCol = col + n.second;
        if (newRow < r && newRow >= 0 && newCol < c && newCol >= 0){
            if (grid[newRow][newCol] == '0'){
                return false;
            }
        }
    }
    return true;
}





void placeTurret(int row, int col){
    
    if (row < 0 || row >= r || col < 0 || col >= c){
        return;
    }

    if (grid[row][col] != '.'){
        return;
    }

    if (check_directions(row,col)){
        Turret newTurret(row,col);
        turrets.push_back(newTurret);
        grid[row][col] = 'x';
    }
}

bool placeOutposts(){
    for (auto& outpost : outposts){
        if (outpost.n == 0) continue;
        int count = 0;

        // Check free spaces in all directions
        for (auto n : dir){
            int row = outpost.x + n.first;
            int col = outpost.y + n.second;
            if (row < r && row >= 0 && col < c && col >= 0){
                if (grid[row][col] == '.'){
                    outpost.freeSpaces.push_back(make_pair(row,col));
                }
                else if (grid[row][col] == 'x')
                    count++;
            }    
        }

        // If not enough free spaces, impossible 👎
        if ((outpost.n - count) > outpost.freeSpaces.size()){
            return false;
        }
        // If just enough free spaces, place turrets 👍
        else if ((outpost.n - count) == outpost.freeSpaces.size()){
            for (auto pair : outpost.freeSpaces){
                Turret newTurret(pair.first,pair.second);
                turrets.push_back(newTurret);
                grid[pair.first][pair.second] = 'x';
            }
        // If more free spaces > turrets needed, place turrets accordingly👍
        }else{
            int placed = 0;
            for (auto freeSpace : outpost.freeSpaces){
                if(check_directions(freeSpace.first, freeSpace.second) ){
                    if(check_for_zeros(freeSpace.first, freeSpace.second)){

                    
                    placed++;
                    Turret newTurret(freeSpace.first,freeSpace.second);
                    turrets.push_back(newTurret);
                    grid[freeSpace.first][freeSpace.second] = 'x';
                }
                if (placed == outpost.n - count){
                    break;
                }
            }
        }
            if (placed != outpost.n - count){
                return false;
            }
        }
    }
    return true;        
}


vector<vector<bool>> covered;

void update_coverage(){
    covered.assign(r, vector<bool>(c, false));
    for (auto& turret : turrets){
        int row = turret.x;
        int col = turret.y;
        covered[row][col] = true;

        for (auto d : dir){
            int newRow = row + d.first;
            int newCol = col + d.second;

            while (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c){
                if (grid[newRow][newCol] == '#' || isdigit(grid[newRow][newCol])) break;
                covered[newRow][newCol] = true;
                newRow += d.first;
                newCol += d.second;
            }
        }
    }
}
bool placeRemainingTurrets(){
    update_coverage();

    bool changed = true;
    while (changed){
        changed = false;
        for (auto& cell : empties){
            int x = cell.x, y = cell.y;
            if (!covered[x][y] && grid[x][y] == '.' && check_directions(x, y)){
                // Place turret
                Turret newTurret(x, y);
                turrets.push_back(newTurret);
                grid[x][y] = 'x';
                update_coverage();
                changed = true;
            }
        }
    }

    // Final coverage check
    for (auto& cell : empties){
        if (!covered[cell.x][cell.y]) return false;
    }
    return true;
}

bool preCheck(){
    for (auto& outpost : outposts){
        if (outpost.n == 0) continue;
        int count = 0;
        for (auto n : dir){
            int row = outpost.x + n.first;
            int col = outpost.y + n.second;
            if (row < r && row >= 0 && col < c && col >= 0){
                if (grid[row][col] == 'x')
                    count++;
            }    
        }
        if (outpost.n < count){
            return false;
        }
    }
    return true;
}



int main(){
    cin >> T;
    char temp;
    
    //Input
    for (int i = 0; i < T; i++){
        cin >> r >> c;
        grid.resize(r, vector<char>(c));
        for (int j = 0; j < r; j++){
            for (int k = 0; k < c; k++){
                cin >> temp;
                grid[j][k] = temp;
                if (temp == '#'){
                    Wall wall(j, k);
                    walls.push_back(wall);
                }
                else if (temp == '.'){
                    EmptySpace empty(j, k);
                    empties.push_back(empty);
                }
                else {
                    temp = temp - '0';
                    Outpost outpost(temp, j, k);
                    outposts.push_back(outpost);
                }
            }
        }

        //placeTurret(0,1);
        //placeTurret(0,3);

        if (!preCheck()){
            cout << "noxus will rise!" << endl;
            continue;
        }
        if (!placeOutposts() || !placeRemainingTurrets()){
            cout << "noxus will rise!" << endl;
            
        }else {
            cout << turrets.size() << endl;
        }


        
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cout << grid[j][k] << " ";
            }
            cout << endl;
        }
        cout << "Turrets: " << turrets.size() << endl;

        
        /*
        for (int j = 0; j < outposts.size(); j++){
            cout << outposts[j].n << " " << outposts[j].x << " " << outposts[j].y << endl;
        }
        for (int j = 0; j < walls.size(); j++){
            cout << walls[j].x << " " << walls[j].y << endl;
        }
        */

        outposts.clear();
        walls.clear();
        turrets.clear();
        empties.clear();
        grid.clear();        
    }
}