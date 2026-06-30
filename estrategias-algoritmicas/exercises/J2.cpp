#include <bits/stdc++.h>
using namespace std;

int timer;
vector<int> disc, low, parent;
vector<bool> visited, isArticulation;

void tarjanAP(int u, const vector<vector<int>>& adj) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            tarjanAP(v, adj);

            low[u] = min(low[u], low[v]);

            // If u is not root and low[v] >= disc[u], then u is an articulation point
            if (parent[u] != -1 && low[v] >= disc[u]) {
                isArticulation[u] = true;
            }

            // If u is root of DFS tree and has two or more children
            if (parent[u] == -1 && children > 1) {
                isArticulation[u] = true;
            }
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int countArticulationPoints(int n, const vector<vector<int>>& adj) {
    timer = 0;
    disc.assign(n + 1, -1);
    low.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    visited.assign(n + 1, false);
    isArticulation.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            tarjanAP(i, adj);
        }
    }

    return count(isArticulation.begin() + 1, isArticulation.end(), true);
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
                adj[v].push_back(u); // Undirected graph
            }
        }

        cout << countArticulationPoints(n, adj) << endl;
    }

    return 0;
}
