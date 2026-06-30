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

void prim(int n, int k){
    int total_weight = 0;
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    set<Edge> q;
    q.insert({0, 0});
    vector<bool> selected(n, false);
    vector<int> degree(n, 0);
    int edges_used = 0;


    for(int i = 0; i < n; ++i){
        if(q.empty()){
            cout << "NO WAY!" << endl;
            return;
        }

        int v = q.begin()->to;
        selected[v] = true;
        edges_used++;
        total_weight += q.begin()->w;
        q.erase(q.begin());


        for(Edge e : adj[v]){
            if(!selected[e.to] && e.w < min_e[e.to].w && degree[v] < k && degree[e.to] < k){
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
                if(v != 0){
                    degree[v]++;
                    degree[e.to]++;
                }



                //selected[e.to] = true;
            }    
        }
    }
    
    
    /*
    vector<pair<int, int>> edges;
    for (int i = 0; i < u; i++) {
        if (min_e[i].to != -1) {
            edges.push_back({min(i, min_e[i].to), max(i, min_e[i].to)});
        }
    }
    */

    if (edges_used < n - 1) {
        cout << "NO WAY!" << endl;
        return;
    }else{
        cout << total_weight << endl;
        return;
    }
    /*
    bool all_selected = true;
    for (bool sel : selected) {
        if (!sel) {
            all_selected = false;
            break;
        }
    }

    if (all_selected) {
        cout << total_weight << endl;
    } else {
        cout << "NO WAY!" << endl;
    }
    */
}

int main(){
    int n, m, k;
    while(cin >> n >> m >> k){
        adj.clear();
        adj.resize(n);
        for(int i = 0; i < m; i++){
            int node1, node2, cost;
            cin >> node1 >> node2 >> cost;
            node1--, node2--;
            adj[node1].push_back({cost, node2});
            adj[node2].push_back({cost, node1});
        }
        prim(n, k);
    }
}