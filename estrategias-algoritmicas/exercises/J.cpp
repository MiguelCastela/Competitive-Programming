#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<int> &visited, vector<vector<int>> &adj, int removed) {
    if (u == removed) {
        return;
    }
    visited[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (visited[v] == 0 && v != removed) {
            DFS(v, visited, adj, removed);
        }
    }
}


int iscritical(int n, vector<vector<int>> &adj) {
    int criticalCount = 0;

    for (int i = 1; i <= n; i++) {
        vector<int> visited(n + 1, 0);

        int start;
        if (i == 1) {
            start = 2;
        } else {
            start = 1;
        }
        DFS(start, visited, adj, i);

        for (int j = 1; j <= n; j++) {
            if (j != i && !visited[j]) {
                criticalCount++;
                break;
            }
        }
    }

    return criticalCount;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        cin.ignore(); 
        vector<vector<int>> adj(n + 1);
        string line;

        while (getline(cin, line)) {
            if (line == "0") break;
            stringstream ss(line);
            int u, v;
            ss >> u;
            while (ss >> v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        cout << iscritical(n, adj) << endl;
    }

    return 0;
}
