#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
 
int R, C; 
int BEST = INT_MAX;
map<char, pair<int, int>> dir = {
    {'U', {-1, 0}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}}
};

map<pair<int, int>, int> outposts;

void print_grids(bool grid_fl, bool cov_grid_fl, vector<vector<char>> &grid, vector<vector<int>> &cov_grid){
    if(grid_fl){
        cout << "Grid: " << endl;
        for(auto i: grid){
            for(auto j: i){
                cout << j << " ";
            }
            cout << endl;
        }
    }

    if(cov_grid_fl){
        cout << "Cov Grid: " << endl;
        for(auto i: cov_grid){
            for(auto j: i){
                cout << j << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

bool in_range(int x, int y, int max_x, int max_y){
    return (
        x >= 0 && x < max_x && 
        y >= 0 && y < max_y
    );
}

bool valid(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &cov_grid){
    return (
        in_range(x, y, (int)grid.size(), (int)grid[0].size()) &&
        cov_grid[x][y] == 0 &&
        grid[x][y] == '.'
    );
}

void remove_turret(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &cov_grid){
    cov_grid[x][y]--;
    grid[x][y] = '.';
    
    for(auto i: dir){
        int dx = i.second.first;
        int dy = i.second.second;
        int nx = x + dx;
        int ny = y + dy;
        while(
            in_range(nx, ny, (int)grid.size(), (int)grid[0].size()) && // In range
            grid[nx][ny] != '#' &&                                     // Not a wall
            !(grid[nx][ny] >= '0' && grid[nx][ny] <= '4')              // Not an outpost
        ){
            cov_grid[nx][ny]--;
            nx += dx;
            ny += dy;
        }
    }
}

int place_turret(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &cov_grid){
    if(grid[x][y] == 'x' || grid[x][y] == '#' || (grid[x][y] >= '0' && grid[x][y] <= '4') || grid[x][y] == 'I'){
        return 0;
    }

    int new_covered = 0;
    int max_x = (int)grid.size();
    int max_y = (int)grid[0].size();
    
    cov_grid[x][y]++;
    if(cov_grid[x][y] == 1){
        new_covered++;
    }
    grid[x][y] = 'x';
    
    for(auto i: dir){
        int dx = i.second.first;
        int dy = i.second.second;
        int nx = x + dx;
        int ny = y + dy;
        while(
            in_range(nx, ny, max_x, max_y) && // In range
            grid[nx][ny] != '#' &&                                     // Not a wall
            !(grid[nx][ny] >= '0' && grid[nx][ny] <= '4')              // Not an outpost
        ){
            cov_grid[nx][ny]++;
            if(cov_grid[nx][ny] == 1){
                new_covered++;
            }
            nx += dx;
            ny += dy;
        }
    }

    for(auto outpost: outposts){
        int o_x = outpost.first.first;
        int o_y = outpost.first.second;
        int required = outpost.second;
        int t_count = 0, empty_count = 0;
        for(auto i: dir){
            int dx = i.second.first;
            int dy = i.second.second;
            int nx = o_x + dx;
            int ny = o_y + dy;
            if(in_range(nx, ny, max_x, max_y)){
                if(grid[nx][ny] == 'x'){
                    t_count++;
                }
                else if(grid[nx][ny] == '.' && cov_grid[nx][ny] == 0){
                    empty_count++;
                }
            }
        }
        if(t_count > required || (t_count + empty_count < required)){
            remove_turret(x, y, grid, cov_grid);
            return 0;
        }

    }

    return new_covered;
}

vector<pair<int, int>> detect_mandatory_turrets(vector<vector<char>> &grid) {
    vector<pair<int, int>> mandatory_positions;
    int R = grid.size(), C = grid[0].size();
    vector<vector<bool>> can_cover(R, vector<bool>(C, false));
    
    // If the cell is an outpost of type N and there are N empty cells around it, then all of them must be
    // covered by a turret, so we add these positions to the mandatory positions and check if they are possible later

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] >= '0' && grid[i][j] <= '4') {
                int required = grid[i][j] - '0';
                int empty_cells = 0;
                
                vector<pair<int, int>> empty_positions;
                for (auto &d : dir) {
                    int ni = i + d.second.first;
                    int nj = j + d.second.second;
                    
                    if (in_range(ni, nj, R, C) && grid[ni][nj] == '.') {
                        empty_cells++;
                        empty_positions.push_back({ni, nj});
                    }
                }
                
                if (empty_cells == required) {
                    for (auto &pos : empty_positions) {
                        mandatory_positions.push_back(pos);
                    }
                }
            }
        }
    }

    return mandatory_positions;
}


bool outpost_constraints_violated(vector<vector<char>> &grid) {
    int max_x = (int)grid.size();   
    int max_y = (int)grid[0].size();

    for(auto outpost: outposts){
        int x = outpost.first.first;
        int y = outpost.first.second;
        int required = outpost.second;
        int max_possible = 0;

        for(auto d: dir){
            int nx = x + d.second.first;
            int ny = y + d.second.second;
            if(in_range(nx, ny, (int)grid.size(), (int)grid[0].size())){
                if(grid[nx][ny] == 'x'){
                    max_possible++;
                } else if(grid[nx][ny] == '.'){
                    max_possible++;
                }
            }
        }
        
        if(max_possible < required){
            return true;
        }

    }
    return false;
}

bool check_around_outpost(int o_x, int o_y, vector<vector<char>> &grid){
    int count = 0; 
    int capacity = outposts[{o_x, o_y}];
    for(auto i: dir){
        int dx = i.second.first;
        int dy = i.second.second;
        int nx = o_x + dx;
        int ny = o_y + dy;
        if(in_range(nx, ny, (int)grid.size(), (int)grid[0].size()) && grid[nx][ny] == 'x'){
            count++;
        }
    }
    return count == capacity;
}

int count_turrets_around_outpost(int o_x, int o_y, vector<vector<char>> &grid){
    int max_x = (int)grid.size();
    int max_y = (int)grid[0].size();

    int turrets_around = 0;

    for(auto i: dir){
        int dx = i.second.first;
        int dy = i.second.second;
        int nx = o_x + dx;
        int ny = o_y + dy;
        if(in_range(nx, ny, max_x, max_y) && grid[nx][ny] == 'x'){
            turrets_around++;
        }
    }

    return turrets_around;
}

bool validate_leaf(vector<vector<char>> &grid, vector<vector<int>> &cov_grid, int uncovered_cells){
    // Every cell must be covered in the cov (if it's not a wall or outpost grid and every outpost must have it's respective ammount of turrets around it
    int max_x = (int)grid.size();
    int max_y = (int)grid[0].size();
    
    if(uncovered_cells != 0){
        return false;
    }
   
    for(auto outpost: outposts){
        int x = outpost.first.first;
        int y = outpost.first.second;
        if(check_around_outpost(x, y, grid)){
            continue;
        }
        else{
            return false;
        }
    }
    
    // for(int i = 0; i < max_x; i++){
    //     for(int j = 0; j < max_y; j++){
    //         if(grid[i][j] >= '0' && grid[i][j] <= '4' && !check_around_outpost(i, j, grid)){
    //             return false;
    //         }
    //     }
    // }


    return true;
}

// floodfill to get regions with minimum-sized grids
vector<vector<vector<char>>> get_regions(vector<vector<char>> &grid) {
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    vector<vector<vector<char>>> regions;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && grid[i][j] != '#') {
                vector<pair<int, int>> region_cells;
                int min_x = R, min_y = C, max_x = 0, max_y = 0;
                
                function<void(int, int)> find_bounds = [&](int x, int y) {
                    visited[x][y] = true;
                    region_cells.push_back({x, y});
                    
                    min_x = min(min_x, x);
                    min_y = min(min_y, y);
                    max_x = max(max_x, x);
                    max_y = max(max_y, y);
                    
                    for (auto &d : dir) {
                        int nx = x + d.second.first;
                        int ny = y + d.second.second;
                        
                        if (in_range(nx, ny, R, C) && grid[nx][ny] != '#' && !visited[nx][ny]) {
                            find_bounds(nx, ny);
                        }
                    }
                };
                
                find_bounds(i, j);
                
                int height = max_x - min_x + 1;
                int width = max_y - min_y + 1;
                vector<vector<char>> region_grid(height, vector<char>(width, '#'));
                
                for (auto &cell : region_cells) {
                    int rel_x = cell.first - min_x;  
                    int rel_y = cell.second - min_y;
                    region_grid[rel_x][rel_y] = grid[cell.first][cell.second];
                }
                
                regions.push_back(region_grid);
            }
        }
    }
    
    return regions;
}

int get_coverage(int x, int y, vector<vector<char>> &grid) {
    int R = grid.size(), C = grid[0].size();
    int coverage = 0;
    
    for (auto &d : dir) {
        int nx = x + d.second.first;
        int ny = y + d.second.second;
        
        while (in_range(nx, ny, R, C) && grid[nx][ny] != '#') {
            if (grid[nx][ny] == '.') coverage++;
            nx += d.second.first;
            ny += d.second.second;
        }
    }
    
    return coverage;
}

void rec(vector<vector<char>> &cur_grid, vector<vector<int>> &cov_grid, int cur_cell, int cur_cost, int uncovered_cells){
    if(cur_cost >= BEST){
        return;
    }

    int max_x = (int)cur_grid.size();
    int max_y = (int)cur_grid[0].size();
    if(cur_cell == max_x * max_y){
        if(validate_leaf(cur_grid, cov_grid, uncovered_cells)){
            BEST = cur_cost;
        }
        return;
    }

    int cur_x = cur_cell / max_y;
    int cur_y = cur_cell % max_y;
        
    
    /*
        if any cell above is not covered and it's not a wall, then we can prune2
    */
    if(
        (
            (cur_grid[cur_x][cur_y] == '#') ||    // It's a wall
            (outposts.count({cur_x, cur_y}) > 0)  // Or it's an outpost
        ) &&  
        (
            cur_x > 0                             // And it's not in the first row
        )
    ){
        // Check if the lines above are covered
        int nx = cur_x - 1;
        while(in_range(nx, cur_y, max_x, max_y)){
            if(cov_grid[nx][cur_y] == 0 && cur_grid[nx][cur_y] == '.'){
                return;
            }
            nx--;
        }
    }
            
    // If it's not possible to cover the outposts, then we can prune
    // if(outpost_constraints_violated(cur_grid)){
    //     return;
    // }

    if(cur_grid[cur_x][cur_y] == '.' && cov_grid[cur_x][cur_y] == 0){
        for(auto d: dir){
            int nx = cur_x + d.second.first;
            int ny = cur_y + d.second.second;
            if(
                in_range(nx, ny, max_x, max_y) && 
                (cur_grid[nx][ny] >= '0' && cur_grid[nx][ny] <= '4') &&
                check_around_outpost(nx, ny, cur_grid)
            ){
                rec(
                    cur_grid, 
                    cov_grid, 
                    cur_cell + 1, 
                    cur_cost, 
                    uncovered_cells
                );
                return;
            }
        }
    }

    if(
        cov_grid[cur_x][cur_y] > 0 ||
        cur_grid[cur_x][cur_y] == 'x' ||
        cur_grid[cur_x][cur_y] == '#' ||
        (cur_grid[cur_x][cur_y] >= '0' && cur_grid[cur_x][cur_y] <= '4') ||
        cur_grid[cur_x][cur_y] == 'I'
    ){
        rec(
            cur_grid, 
            cov_grid, 
            cur_cell + 1, 
            cur_cost, 
            uncovered_cells
        );
        return;
    }



    if(valid(cur_x, cur_y, cur_grid, cov_grid)){
        int new_covered = place_turret(cur_x, cur_y, cur_grid, cov_grid);
    
        if(new_covered > 0){
            rec(
                cur_grid, 
                cov_grid, 
                cur_cell + 1, 
                cur_cost + 1, 
                uncovered_cells - new_covered
            );
            remove_turret(cur_x, cur_y, cur_grid, cov_grid);
        }
        
    }

  
    rec(
        cur_grid, 
        cov_grid, 
        cur_cell + 1, 
        cur_cost, 
        uncovered_cells
    );
    return;
}


// Helper function to process a region before backtracking
bool preprocess_region(vector<vector<char>>& region, vector<vector<int>>& cov_grid, int& cur_cost, int& uncovered_cells) {
    int max_x = region.size();
    int max_y = region[0].size();
    
    // Check if outposts have enough empty spaces around them
    for(auto& outpost : outposts) {
        int x = outpost.first.first, y = outpost.first.second;
        int required = outpost.second;
        int empty_cells = 0;
        
        for(auto& d : dir) {
            int nx = x + d.second.first, ny = y + d.second.second;
            if(in_range(nx, ny, max_x, max_y) && region[nx][ny] == '.')
                empty_cells++;
        }
        
        if(empty_cells < required)
            return false; // Cannot satisfy outpost requirements
    }
    
    // Place turrets for outposts with exact requirements
    for(auto& outpost : outposts) {
        int x = outpost.first.first, y = outpost.first.second;
        int required = outpost.second;
        
        // Handle outpost with exact number of spots required
        if(required == 4) {
            for(auto& d : dir) {
                int nx = x + d.second.first, ny = y + d.second.second;
                if(in_range(nx, ny, max_x, max_y) && region[nx][ny] == '.' && cov_grid[nx][ny] == 0) {
                    int new_covered = place_turret(nx, ny, region, cov_grid);
                    uncovered_cells -= new_covered;
                    cur_cost++;
                }
                else if(!(in_range(nx, ny, max_x, max_y) && region[nx][ny] == 'x')) {
                    return false;
                }
            }
        }
        else if((required == 3 || required == 2) && 
                (x == 0 || x == max_x - 1) && (y == 0 || y == max_y - 1)) {
            int miss = 0;
            for(auto& d : dir) {
                int nx = x + d.second.first, ny = y + d.second.second;
                if(in_range(nx, ny, max_x, max_y) && region[nx][ny] == '.' && cov_grid[nx][ny] == 0) {
                    int new_covered = place_turret(nx, ny, region, cov_grid);
                    uncovered_cells -= new_covered;
                    cur_cost++;
                }
                else if(!(in_range(nx, ny, max_x, max_y) && region[nx][ny] == 'x')) {
                    miss++;
                }
            }
            if(miss > (required == 3 ? 1 : 2))
                return false;
        }

        /*  ISTO NAO FAZ SENTIDO NENHUM !!!!!!!!!!!!!!!!!!!!!!!!!!
            !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        */
        



    }
    
    // Iterate until no more turrets can be placed deterministically
    bool made_progress = true;
    while(made_progress) {
        made_progress = false;
        
        // Place turrets for outposts with exact remaining requirements
        for(auto& outpost : outposts) {
            int x = outpost.first.first, y = outpost.first.second;
            int required = outpost.second;
            int available = 0;
            
            for(auto& d : dir) {
                int nx = x + d.second.first, ny = y + d.second.second;
                if((in_range(nx, ny, max_x, max_y) && region[nx][ny] == '.' && cov_grid[nx][ny] == 0) || 
                   (in_range(nx, ny, max_x, max_y) && region[nx][ny] == 'x'))
                    available++;
            }
            
            if(available == required) {
                for(auto& d : dir) {
                    int nx = x + d.second.first, ny = y + d.second.second;
                    if(in_range(nx, ny, max_x, max_y) && region[nx][ny] == '.' && cov_grid[nx][ny] == 0) {
                        int new_covered = place_turret(nx, ny, region, cov_grid);
                        if(new_covered != 0) {
                            uncovered_cells -= new_covered;
                            cur_cost++;
                            made_progress = true;
                        }
                        else return false;
                    }
                }
            }
        }
        
        // Handle cells surrounded by obstacles
        for(int i = 0; i < max_x; i++) {
            for(int j = 0; j < max_y; j++) {
                if(region[i][j] != '.') continue;
                
                int blocked = 0;
                for(auto& d : dir) {
                    int nx = i + d.second.first, ny = j + d.second.second;
                    if(!in_range(nx, ny, max_x, max_y) || 
                       region[nx][ny] == '#' || (region[nx][ny] >= '0' && region[nx][ny] <= '4'))
                        blocked++;
                }
                
                if(blocked == 4 && region[i][j] == '.') {
                    int new_covered = place_turret(i, j, region, cov_grid);
                    if(new_covered != 0) {
                        uncovered_cells -= new_covered;
                        cur_cost++;
                        made_progress = true;
                    }
                    else return false;
                }
            }
        }
        
        // Place turrets in cells that can't be covered by any other cell
        for(int i = 0; i < max_x; i++) {
            for(int j = 0; j < max_y; j++) {
                if(region[i][j] != '.' || cov_grid[i][j] != 0) continue;
                
                bool required = true;
                for(auto& d : dir) {
                    int ni = i + d.second.first, nj = j + d.second.second;
                    while(in_range(ni, nj, max_x, max_y) && 
                          !(region[ni][nj] == '#' || (region[ni][nj] >= '0' && region[ni][nj] <= '4'))) {
                        if(cov_grid[ni][nj] == 0 && region[ni][nj] == '.') {
                            required = false;
                            break;
                        }
                        ni += d.second.first;
                        nj += d.second.second;
                    }
                    if(!required) break;
                }
                
                if(required) {
                    int new_covered = place_turret(i, j, region, cov_grid);
                    if(new_covered != 0) {
                        uncovered_cells -= new_covered;
                        cur_cost++;
                        made_progress = true;
                    }
                    else return false;
                }
            }
        }
        
        // Mark cells that cannot have turrets (near satisfied outposts)
        for(auto& outpost : outposts) {
            int x = outpost.first.first, y = outpost.first.second;
            if(check_around_outpost(x, y, region)) {
                for(auto& d : dir) {
                    int nx = x + d.second.first, ny = y + d.second.second;
                    if(in_range(nx, ny, max_x, max_y) && region[nx][ny] == '.')
                        region[nx][ny] = 'I';
                }
            }
        }
        
        // Find mandatory turret placements for cells marked as impossible
        for(int i = 0; i < max_x; i++) {
            for(int j = 0; j < max_y; j++) {
                if(region[i][j] != 'I' || cov_grid[i][j] != 0) continue;
                
                int count = 0;
                int new_x = -1, new_y = -1;
                
                for(auto& d : dir) {
                    int ni = i + d.second.first, nj = j + d.second.second;
                    while(in_range(ni, nj, max_x, max_y) && 
                          !(region[ni][nj] == '#' || (region[ni][nj] >= '0' && region[ni][nj] <= '4'))) {
                        if(cov_grid[ni][nj] == 0 && region[ni][nj] == '.') {
                            count++;
                            new_x = ni;
                            new_y = nj;
                        }
                        ni += d.second.first;
                        nj += d.second.second;
                    }
                }
                
                if(count == 1) {
                    int new_covered = place_turret(new_x, new_y, region, cov_grid);
                    if(new_covered != 0) {
                        uncovered_cells -= new_covered;
                        cur_cost++;
                        made_progress = true;
                    }
                    else return false;
                }
                else if(count == 0) return false;
            }
        }
    }
    
    // Check if we've already solved the region
    if(validate_leaf(region, cov_grid, uncovered_cells))
        return true;
        
    if(uncovered_cells == 0) {
        for(auto& outpost : outposts) {
            int x = outpost.first.first, y = outpost.first.second;
            int ct = 0;
            for(auto& d : dir) {
                int nx = x + d.second.first, ny = y + d.second.second;
                if(in_range(nx, ny, max_x, max_y) && region[nx][ny] == 'x')
                    ct++;
            }
            if(ct != outpost.second)
                return false;
        }
        return true;
    }
    
    return true; // Continue with backtracking
}

void solve() {
    cin >> R >> C; 
    BEST = INT_MAX;
    vector<vector<char>> grid(R, vector<char>(C));
    vector<vector<int>> cov_grid(R, vector<int>(C, 0));
    outposts.clear();

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int sum = 0; 
    vector<vector<vector<char>>> regions = get_regions(grid);

    for(auto& region : regions) {
        int uncovered_cells = 0;
        int max_x = region.size(), max_y = region[0].size();

        // Get outposts for this region and count uncovered cells
        outposts.clear();
        for(int i = 0; i < max_x; i++) {
            for(int j = 0; j < max_y; j++) {
                if(region[i][j] == '.') {
                    uncovered_cells++;
                }
                else if(region[i][j] >= '0' && region[i][j] <= '4') {
                    outposts[{i, j}] = region[i][j] - '0';
                }
            }
        }

        vector<vector<int>> cov_grid(max_x, vector<int>(max_y, 0));
        int cur_cost = 0;

        // Apply pre-processing
        bool possible = preprocess_region(region, cov_grid, cur_cost, uncovered_cells);
        
        if(!possible) {
            cout << "noxus will rise!" << endl;
            return;
        }
        
        // If pre-processing solved the region
        if(validate_leaf(region, cov_grid, uncovered_cells) || uncovered_cells == 0) {
            sum += cur_cost;
            continue;
        }

        // Region needs backtracking
        BEST = INT_MAX;
        rec(region, cov_grid, 0, cur_cost, uncovered_cells);
        
        if(BEST == INT_MAX) {
            cout << "noxus will rise!" << endl;
            return; 
        }
        sum += BEST; 
    }
    
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}