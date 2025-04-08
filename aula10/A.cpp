#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s, const char delimiter) {
vector<string> tokens;
string token;
istringstream tokenStream(s);
while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
}
return tokens;
}

vector<int> visited;
vector<vector<int> > adj;
int DFS(int u){
    visited[u] = 1;
    for(int v = 0; v < adj[u].size(); v++){
        if(visited[adj[u][v]] == 0){ 
            DFS(adj[u][v]);
        }
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num_cities;
    cin >> num_cities;
    for(int i=0; i<num_cities; i++){
        int num_roads;
        cin >> num_roads;
        int num_connected;
        cin >> num_connected;
        visited.resize(num_roads+1,0);
        adj.resize(num_roads+1);
        for(int j=0; j<num_connected; j++){
            int city1,city2;
            cin >> city1 >> city2;
            adj[city1].push_back(city2);
            adj[city2].push_back(city1);
        }
        DFS(0);
        int count = 0;
        for(int k=1; k<num_roads; k++){
            if(visited[k] == 0){
                DFS(k);
                count++;
   
            }
        }
        cout << count << endl;
        visited.clear();
        adj.clear();
    }
}