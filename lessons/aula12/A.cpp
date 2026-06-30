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

void prim(vector<vector<Edge>> adj, int u){
    int total_weight = 0;
    vector<Edge> min_e(u);
    min_e[0].w = 0;
    set<Edge> q;
    q.insert({0, 0});
    vector<bool> selected(u, false);
    bool flag = false;

    for(int i=0; i<u; ++i){
        if(q.empty()){
            cout << "Impossible" << endl;
            flag = true;
            return;
        }

        int v = q.begin()->to;
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        for(Edge e : adj[v]){
            if(!selected[e.to] && e.w < min_e[e.to].w){
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }
    }

    cout << total_weight << endl;
    vector<pair<int, int>> res;
    for (int i = 0; i < u; i++) {
        if (min_e[i].to != -1) {
            cout << min(min_e[i].to, i) << " " << max(min_e[i].to, i) << endl;
        }
    }
    return;
}

int main(){


    while(true){
        int nodes;
        int edges;
        int u, v, w;

        cin >> nodes >> edges;
        if (nodes == 0 && edges == 0){
            break;
        }

        adj.resize(nodes);
        for(int i=0; i<edges; ++i){
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
            
        } 
        prim(adj, nodes);
        adj.clear();
    }
}