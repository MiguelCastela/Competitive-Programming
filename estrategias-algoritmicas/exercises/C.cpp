#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

struct Edge {
    int w = INF, to = -1;
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

vector<vector<Edge>> adj;
int total_weight = INF;

void backtrack(int edges_used, int current_weight, vector<bool>& selected, vector<int>& degree, int n, int k) {
    if (edges_used == n - 1) {  
        total_weight = min(total_weight, current_weight);
        return;
    }

    if(current_weight >= total_weight){
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!selected[i]) continue;  

        for (Edge e : adj[i]) {
            if (!selected[e.to] && degree[i] < k && degree[e.to] < k) {
                selected[e.to] = true;
                degree[i]++;
                degree[e.to]++;
                current_weight += e.w;
                edges_used++;

                backtrack(edges_used, current_weight, selected, degree, n, k);

                selected[e.to] = false;
                degree[i]--;
                degree[e.to]--;
                current_weight -= e.w;
                edges_used--;
            }
        }
    }
}

void prim(int n, int k) {
    vector<bool> selected(n, false);
    vector<int> degree(n, 0);
    int current_weight = 0;
    int edges_used = 0;

    selected[0] = true;
    backtrack(edges_used, current_weight, selected, degree, n, k);

    if (total_weight == INF) {
        cout << "NO WAY!" << endl;
    } else {
        cout << total_weight << endl;
    }
}

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < m; i++) {
            int node1, node2, cost;
            cin >> node1 >> node2 >> cost;
            node1--, node2--;
            adj[node1].push_back({cost, node2});
            adj[node2].push_back({cost, node1});
        }
        total_weight = INF;
        prim(n, k);
    }
    return 0;
}
