#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int n, m, k, mn; 
vector<vector<int>> graph;
 
bool is_connected(vector<vector<int>> &graph){
    if(graph.size() == 0){
        return true;
    }

    // create adj list
    vector<vector<int>> adj(n + 1);
    for(auto x: graph){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    int count = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto x: adj[cur]){
            if(visited[x] == 0){
                visited[x] = 1;
                count++;
                q.push(x);
            }
        }
    }

    return count == n;
}


void rec(int cur_cost, int node_count, int idx, vector<int> &conn_count, vector<vector<int>> &cur_graph){
    if(cur_cost >= mn){
        return;
    }


    if(node_count == n - 1){
        // print graph
        if(cur_cost == -1){
            for(auto x: cur_graph){
                cout << x[0] << " " << x[1] << " " << x[2] << endl;
            }
            cout << cur_cost << endl << endl;
            
        }
        if(is_connected(cur_graph)){
            mn = min(mn, cur_cost);
        }
        return;
    }

    if(idx == m){


        return;
    }
    int u = graph[idx][0];
    int v = graph[idx][1];
    int w = graph[idx][2];

    if(conn_count[u] > 0 && conn_count[v] > 0){
        conn_count[u]--;
        conn_count[v]--;
        cur_graph.push_back({u, v, w});
        rec(cur_cost + w, node_count + 1, idx + 1, conn_count, cur_graph);
        cur_graph.pop_back();
        conn_count[u]++;
        conn_count[v]++;
    }
    
    rec(cur_cost, node_count, idx + 1, conn_count, cur_graph);
}

void solve(){
    while(cin >> n >> m >> k){
        mn = INT_MAX;
        graph = vector<vector<int>>();
        for(int i = 0; i < m; i++){
            vector<int> add(3);
            cin >> add[0] >> add[1] >> add[2];
            graph.push_back(add);
        }

        // sort(graph.begin(), graph.end(), [](vector<int> &a, vector<int> &b){
        //     return a[2] < b[2];
        // });

        vector<int> conn_count(n + 1, k);
        vector<int> visited(n + 1, 0);
        vector<vector<int>> cur_graph;
        rec(0, 0, 0, conn_count, cur_graph);
        if(mn == INT_MAX) {
            cout << "NO WAY!\n";
        }
        else{
            cout << mn << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    for(int it=1;it<=t;it++) {
     //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}