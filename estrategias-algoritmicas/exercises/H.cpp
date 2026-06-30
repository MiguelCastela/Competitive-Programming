#include <bits/stdc++.h>
using namespace std;

bool DFS(int u, vector<int>& color, vector<vector<int>>& adj) {
    for (int v : adj[u]) {
        if (color[v] == -1) {
            color[v] = 1 - color[u];
            if (!DFS(v, color, adj)){
                return false;
            }
        } else if (color[v] == color[u]) {
            return false;
        }
    }   
    return true;
}

bool check(int n, vector<vector<int>> &vec){
    vector<int> color(n + 1, -1);

    for(int i= 0; i<=n; ++i) {
        if(color[i] == -1){
            color[i] = 0;
            if(!DFS(i, color, vec)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    
    while(cin >> n >> m){
        vector<vector<int>> vec(n+1);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);

        }
        if (check(n, vec)) {
            cout << "NOT SURE" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
    