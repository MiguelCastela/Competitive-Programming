#include <bits/stdc++.h>

using namespace std;

map<int , int> visited;
map<int, vector<int> > adj;

void BFS(int v, int ttl){
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while(!q.empty() && ttl > 0){
        int level = q.size();
         for (int i = 0; i < level; i++) {
            int u = q.front();
            q.pop();
            for(auto w : adj[u]){
                if(visited[w] == 0){
                    visited[w] = 1;
                    q.push(w);
                }
            }
        }
        ttl--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num_cases = 1;
    while (true){
        adj.clear();
        visited.clear();
        int u, v;
        int num_adj;
        cin >> num_adj;

        if(num_adj == 0) break;
        for(int i = 0; i < num_adj; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int init_node;
        int ttl;


        while(true){
            cin >> init_node >> ttl;
            if(init_node == 0 && ttl == 0) break;
            visited.clear();
            for(auto p : adj){
                visited[p.first] = 0;
            }

            BFS(init_node, ttl);
            int count = 0;
            for(auto i : visited){
                if(i.second == 0) count++;
            }
            cout << "Case " << num_cases << ": " << count << " nodes not reachable from node " << init_node << " with TTL = " << ttl << ".\n";
            num_cases++;
        }
        
        // cout << adj.size() << endl;
        // for (auto p : adj) {
        //     cout << "here" << endl;
        //     cout << "Node " << p.first << ": ";
        //     cout << p.second.size() << endl;
        //     for (int neighbor : p.second) {
        //         cout << neighbor << " ";
        //         }
        //     cout << endl;
        // }
        // cout << "ola" << endl;
        // break;
    }

    return 0;
}