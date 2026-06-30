#include <bits/stdc++.h>
using namespace std;


int T, r, c;
int best = INT_MAX;

vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
map<pair<int,int>, int> outposts;



bool isCellValid(int row, int col, int r, int c){
    if (row < r && row >= 0 && col < c && col >= 0){
        return true;
    }
    return false;
}


vector<pair<int, int>> floodFill(int startRow, int startCol, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
    int r = grid.size();
    int c = grid[0].size();
    queue<pair<int, int>> q;  
    vector<pair<int, int>> region;  

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;
    region.push_back({startRow, startCol});

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        for (auto [dr, dc] : dir) {
            int newRow = row + dr;
            int newCol = col + dc;

            if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c &&
                !visited[newRow][newCol] && grid[newRow][newCol] != '#') {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
                region.push_back({newRow, newCol});
            }
        }
    }

    return region;
}

vector<vector<pair<int, int>>> makeRegions(vector<vector<char>> &grid) {
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<bool>> visited(r, vector<bool>(c, false)); 
    vector<vector<pair<int, int>>> regions; 

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != '#' && !visited[i][j]) {
                vector<pair<int, int>> region = floodFill(i, j, grid, visited);
                regions.push_back(region); 
            }
        }
    }

    return regions;
}


vector<vector<vector<char>>> convertToGrid(vector<vector<pair<int, int>>>& regions, vector<vector<char>>& grid) {
    int regionCount = regions.size(); 
    int rows = r, cols = c;
    vector<vector<vector<char>>> regionGrids(regionCount, vector<vector<char>>(rows, vector<char>(cols, '#')));

    int i = 0;
    for (const auto& region : regions) {
        for (auto p: region) {
            int row = p.first;
            int col = p.second;
            if (row >= 0 && row < rows && col >= 0 && col < cols) {
                regionGrids[i][row][col] = grid[row][col]; 
            }
        }
        i++;
    }

    return regionGrids;
}

    


void printGrids(vector<vector<char>> &grid, vector<vector<int>> &coverageGrid) {
    cout << "Grid:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Coverage Grid:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << coverageGrid[i][j] << ' ';
        }
        cout << endl;
    }
}

bool checkAbove(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &coverageGrid){

    while (row < r && row > 0 && col < c && col >= 0){ // in bounds
            row--;
            if (grid[row][col] == '.' && coverageGrid[row][col] == 0){
                return false;
            }
        }
        return true;
    }


int placeTurret(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &coverageGrid){

    if (row < 0 || row >= r || col < 0 || col >= c){
        return 0;
    }
    
    if (grid[row][col] != '.'){
        return 0;
    }
    
    grid[row][col] = 'x';
    coverageGrid[row][col] = 1;
    int newCovered = 1;

    for (auto n : dir){
        int newRow = row + n.first;
        int newCol = col + n.second;

        while (newRow < r && newRow >= 0 
                && newCol < c && newCol >= 0 
                && grid[newRow][newCol] != '#' 
                && !(isdigit(grid[newRow][newCol])))
                {

                coverageGrid[newRow][newCol]++;
                if (coverageGrid[newRow][newCol] == 1){
                    newCovered++;
                }

                newRow += n.first;
                newCol += n.second;
            }
        }
        
        return newCovered;
    }


void removeTurret(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &coverageGrid){

    coverageGrid[row][col]--;
    grid[row][col] = '.';
    
    for (auto n : dir){
        int newRow = row + n.first;
        int newCol = col + n.second;

        while (newRow < r && newRow >= 0 
                && newCol < c && newCol >= 0 
                && grid[newRow][newCol] != '#' 
                && !(grid[newRow][newCol] >= '0' && grid[newRow][newCol] <= '4'))
            {
            coverageGrid[newRow][newCol]--;
           
            newRow += n.first;
            newCol += n.second;
        }
    }
}

bool areOutpostsValid(vector<vector<char>> &grid){

    for(auto outpost: outposts){
        if (outpost.second == 0){
            continue;
        }
        int row = outpost.first.first;
        int col = outpost.first.second;
        int count = 0;

        for (auto n : dir){
            int newRow = row + n.first;
            int newCol = col + n.second;
            if(isCellValid(newRow, newCol, r, c) && (grid[newRow][newCol] == 'x' || grid[newRow][newCol] == '.')){
                count++;
            }
        }
        if (count < outpost.second){
            return false;
        }
    }
    return true;
}

bool isSolutionValid(vector<vector<char>> &grid, vector<vector<int>> &coverageGrid, int emptySpaces){
    
    if(emptySpaces != 0){
        return false;
    }

    for(auto outpost: outposts){
        int row = outpost.first.first;
        int col = outpost.first.second;
        int count = 0;
        for (auto n : dir){
            int newRow = row + n.first;
            int newCol = col + n.second;
            if(isCellValid(newRow, newCol, r, c) && grid[newRow][newCol] == 'x'){
                count++;
            }
        }
        if (count != outpost.second){
            // if(grid == corr){

            //     cout << "fuckaoutpost" << outpost.first.first << " " << outpost.first.second << endl;
            //     for(auto outpos: outposts){
            //         cout << outpos.first.first << " " << outpos.first.second << " " << outpos.second << endl;
            //     }
            // }
            return false;
        }
    }

    return true;
}

bool preProcess(vector<vector<char>> &grid, vector<vector<int>> &coverageGrid, int &emptySpaces, int &cost){
    

    for(auto outpost: outposts){
        int row = outpost.first.first;
        int col = outpost.first.second;
        int count = 0;

        if (outpost.second == 0){
            continue;
        }

        if ((outpost.second == 4 || outpost.second == 3) && 
            ((row == 0 && col == 0) || (row == 0 && col == c - 1) || 
             (row == r - 1 && col == 0) || (row == r - 1 && col == c - 1))) {
                return false;
             }
            

        if (outpost.second == 4 && 
            (row == 0 || row == r - 1 || col == 0 || col == c - 1)) {
            return false;
        }

        for (auto n : dir){
            int newRow = row + n.first;
            int newCol = col + n.second;
            if(isCellValid(newRow, newCol, r, c) && grid[newRow][newCol] == '.'){
                count++;
            }
        }
        if (count < outpost.second){
            return false;
        }

    }




    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(coverageGrid[i][j] == 0 && grid[i][j] == '.'){
            int wallCount = 0;
            for (auto n : dir){
                int newRow = i + n.first;
                int newCol = j + n.second;
                if (isCellValid(newRow, newCol,r,c) && (grid[newRow][newCol] == '#' || isdigit(grid[newRow][newCol]))){
                    wallCount++;
                }
            }
            if (wallCount == 4){
                int coveredSpaces = placeTurret(i, j, grid, coverageGrid);
                emptySpaces -= coveredSpaces;
                cost++;
            }
        }
    }       
}
    for(auto outpost: outposts){
        int row = outpost.first.first;
        int col = outpost.first.second;
        int empty = 0;
        int placed = 0;

        for (auto n : dir){
            int newRow = row + n.first;
            int newCol = col + n.second;
            if(isCellValid(newRow, newCol,r,c) && grid[newRow][newCol] == '.' && coverageGrid[newRow][newCol] == 0){
                empty++;
            } else if (isCellValid(newRow,newCol,r,c) && grid[newRow][newCol] == 'x'){
                placed++;
            }
        }
        

        if (empty == outpost.second - placed){
            
            for (auto n : dir){
                int newRow = row + n.first;
                int newCol = col + n.second;
                if(isCellValid(newRow, newCol,r,c) && grid[newRow][newCol] == '.' && coverageGrid[newRow][newCol] == 0){
                    int coveredSpaces = placeTurret(newRow, newCol, grid, coverageGrid);
                    emptySpaces -= coveredSpaces;
                    cost++;
                }
            }
            
        }
    }

    return true;
        
}

void backtrack(int idx, vector<vector<char>> &grid, vector<vector<int>> &coverageGrid, int emptySpaces, int cost){    
    if (!areOutpostsValid(grid)){
        return;
    }
    if (cost >= best){
        return;
    }
    
    if(idx == c*r){
        if (isSolutionValid(grid, coverageGrid, emptySpaces)){
            best = cost;
        }
        return;
    }

    int row = idx / c;
    int col = idx % c;

    
    // is # is digit or is x then skip

    
    if (row > 0 && (grid[row][col] == '#' || isdigit(grid[row][col]))){
        if (!checkAbove(row, col, grid, coverageGrid)){
            return;
        }
    }

    
    
    if(grid[row][col] == '#' || isdigit(grid[row][col]) || grid[row][col] == 'x' || coverageGrid[row][col] > 0 || grid[row][col] == 'Z'){
        backtrack(idx + 1, grid, coverageGrid, emptySpaces, cost);
        return;
    }
    
    if(isCellValid(row, col,r,c)){
        int covered = placeTurret(row, col, grid, coverageGrid);
        backtrack(idx + 1, grid, coverageGrid, emptySpaces - covered, cost + 1);
        removeTurret(row, col, grid, coverageGrid);
    }
    
    backtrack(idx + 1, grid, coverageGrid, emptySpaces, cost);



}

int main(){


    cin >> T;
    char temp;
    
    //Input
    for (int i = 0; i < T; i++){
        cin >> r >> c;
        vector<vector<char>> grid;
        grid.resize(r, vector<char>(c));
        vector<vector<int>> coverageGrid;
        
        outposts.clear();
        int emptySpaces = 0;
        for (int j = 0; j < r; j++){
            for (int k = 0; k < c; k++){
                cin >> temp;
                grid[j][k] = temp;
            }
        }

        for (int j = 0; j < r; j++){
            for (int k = 0; k < c; k++){
                if (grid[j][k] == '0'){
                    for (auto n : dir) {
                        int newRow = j + n.first;
                        int newCol = k + n.second;
                        if (isCellValid(newRow, newCol, r, c) && grid[newRow][newCol] == '.') {
                            grid[newRow][newCol] = 'Z';
                        }
                    }
                }
            }
        }

        

        vector<vector<pair<int, int>>> regions = makeRegions(grid);
        vector<vector<vector<char>>> regionGrids = convertToGrid(regions, grid);
        int total_cost = 0;
        for (int i = 0; i < regionGrids.size(); i++) {

            /*
            cout << "Region " << i + 1 << ":" << endl;
            for (const auto& row : regionGrids[i]) {
                for (const auto& cell : row) {
                    cout << cell << ' ';
                }
                cout << endl;
            }
                */
            
            vector<vector<char>> regionGrid = regionGrids[i];
            vector<vector<int>> regionCoverageGrid(r, vector<int>(c, 0));
            int regionEmptySpaces = 0;
            outposts.clear();

            for (int row = 0; row < r; row++) {
                for (int col = 0; col < c; col++) {
                    if (regionGrid[row][col] == '.' || regionGrid[row][col] == 'Z') {
                        regionEmptySpaces++;
                    }
                    else if (isdigit(regionGrid[row][col])) {
                        outposts[{row, col}] = regionGrid[row][col] - '0';
                    }
                }
            }
            int regionCost = 0;
            if (!preProcess(regionGrid, regionCoverageGrid, regionEmptySpaces, regionCost)) {
                total_cost = INT_MAX;
                break;
            }

            best = INT_MAX;
            backtrack(0, regionGrid, regionCoverageGrid, regionEmptySpaces, regionCost);

            if (best == INT_MAX) {
                total_cost = INT_MAX;
                break;
            }
            total_cost += best;


        }
        
        
        if (total_cost == INT_MAX){
            cout << "noxus will rise!" << endl;
        } else  {
            cout << total_cost << endl;
        }

            


    }
}