#include <bits/stdc++.h> // Remove this if using Mac
#include <math.h>
using namespace std;

class Outpost {
public:
    int n;
    int x, y;
    vector<pair<int, int>> freeSpaces;
    Outpost(int n, int x_coord, int y_coord) : n(n), x(x_coord), y(y_coord) {}
};

class Wall {
public:
    int x, y;
    Wall(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
};

class Turret {
public:
    int x, y;
    Turret(int x_coord, int y_coord) : x(x_coord), y(y_coord) {}
};

int T, r, c, minTurrets = INT_MAX;
vector<vector<char>> grid;
vector<Outpost> outposts;
vector<Wall> walls;
vector<Turret> turrets;
vector<pair<int, int>> empties;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool check_direction(int row, int col, int n) {
    row += dir[n].first;
    col += dir[n].second;
    if (row >= r || row < 0 || col >= c || col < 0) return true;
    if (grid[row][col] == 'x') return false;
    if (grid[row][col] == '.') return check_direction(row, col, n);
    return true;
}

bool check_directions(int row, int col) {
    return check_direction(row, col, 0) && check_direction(row, col, 1) &&
           check_direction(row, col, 2) && check_direction(row, col, 3);
}

void placeTurret(int row, int col) {
    grid[row][col] = 'x';
    turrets.push_back(Turret(row, col));
}

void removeTurret(int row, int col) {
    grid[row][col] = '.';
    turrets.pop_back();
}

bool validateOutposts() {
    for (auto& outpost : outposts) {
        int count = 0;
        for (auto d : dir) {
            int x = outpost.x + d.first, y = outpost.y + d.second;
            if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == 'x')
                count++;
        }
        if (count != outpost.n) return false;
    }
    return true;
}

void backtrack(int idx, int placed) {
    if (placed >= minTurrets) return; // Prune bad solutions
    if (idx == empties.size()) {
        if (validateOutposts()) {
            minTurrets = min(minTurrets, placed);
        }
        return;
    }
    
    int row = empties[idx].first, col = empties[idx].second;
    if (check_directions(row, col)) {
        placeTurret(row, col);
        backtrack(idx + 1, placed + 1);
        removeTurret(row, col);
    }
    backtrack(idx + 1, placed); // Try skipping this position
}

int main() {
    cin >> T;
    char temp;
    for (int t = 0; t < T; t++) {
        cin >> r >> c;
        grid.assign(r, vector<char>(c));
        outposts.clear();
        walls.clear();
        turrets.clear();
        empties.clear();
        minTurrets = INT_MAX;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> temp;
                grid[i][j] = temp;
                if (temp == '#') walls.emplace_back(i, j);
                else if (temp == '.') empties.emplace_back(i, j);
                else outposts.emplace_back(temp - '0', i, j);
            }
        }
        
        backtrack(0, 0);
        
        if (minTurrets == INT_MAX) cout << "noxus will rise!" << endl;
        else cout << minTurrets << endl;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
            cout << grid[i][j];
            }
            cout << endl;
        }

        cout << "Turrets placed at: ";
        for (auto& turret : turrets) {
            cout << "(" << turret.x << ", " << turret.y << ") ";
        }
        cout << endl;
    }
}

