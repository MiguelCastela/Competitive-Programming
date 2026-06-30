3#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, k;
vector<tuple<int, int, int>> edges;
int min_cost;

void backtrack(int idx, vector<pair<int, int>>& tree, vector<int>& degree, int cost) {
    if (tree.size() == n - 1) {
        vector<int> root(n);
        iota(root.begin(), root.end(), 0);

        function<int(int)> find = [&](int x) {
            return root[x] == x ? x : root[x] = find(root[x]);
        };

        for (auto [u, v] : tree) {
            root[find(v)] = find(u);
        }

        int root_component = find(0);
        if (all_of(root.begin(), root.end(), [&](int x) { return find(x) == root_component; })) {
            min_cost = min(min_cost, cost);
        }
        return;
    }

    if (idx >= m) return;

    auto [w, u, v] = edges[idx];

    if (degree[u] < k && degree[v] < k) { 
        tree.push_back({u, v});
        degree[u]++;
        degree[v]++;

        backtrack(idx + 1, tree, degree, cost + w);

        tree.pop_back();
        degree[u]--;
        degree[v]--;
    }

    backtrack(idx + 1, tree, degree, cost);
}

void solve() {
    while (cin >> n >> m >> k) { 
        edges.clear();
        min_cost = INF;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.emplace_back(w, u - 1, v - 1); 
        }

        sort(edges.begin(), edges.end());

        vector<pair<int, int>> tree;
        vector<int> degree(n, 0);

        backtrack(0, tree, degree, 0);

        if (min_cost == INF) {
            cout << "NO WAY!" << endl;
        } else {
            cout << min_cost << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
