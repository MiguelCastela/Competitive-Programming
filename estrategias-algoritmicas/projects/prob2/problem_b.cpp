#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Union-Find (Disjoint Set Union) with Path Compression
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if(xr == yr) return;
        if(rank[xr] < rank[yr])
            parent[xr] = yr;
        else if(rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }
};

struct Edge {
    int u, v, cost;
};

bool cmp(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

// Check if with max cost allowed, mandatory towers are connected
bool can_connect(int n, const vector<Edge>& edges, const set<int>& mandatory, int max_cost) {
    DSU dsu(n);
    for(const Edge& e : edges) {
        if(e.cost <= max_cost)
            dsu.unite(e.u, e.v);
    }

    auto it = mandatory.begin();
    int first = *it;
    ++it;
    for(; it != mandatory.end(); ++it) {
        if(dsu.find(first) != dsu.find(*it))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, E;
    while(cin >> N >> E) {
        vector<Edge> edges(E);
        for(int i = 0; i < E; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].cost;
        }

        int M;
        cin >> M;
        set<int> mandatory;
        for(int i = 0; i < M; ++i) {
            int node;
            cin >> node;
            mandatory.insert(node);
        }

        sort(edges.begin(), edges.end(), cmp);

        int low = 0, high = edges.back().cost, answer = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(can_connect(N, edges, mandatory, mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(answer == -1)
            cout << "Impossible to connect!" << '\n';
        else
            cout << answer << '\n';
    }

    return 0;
}
