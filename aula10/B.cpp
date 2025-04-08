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

int t = 0;
vector<int> visited;
vector <vector<int> > adj;
int DFS(int u){
    visited[u] = 1;
    for(int v = 0; v < adj[u].size(); v++){
        if(visited[adj[u][v]] == 0){ 
            DFS(adj[u][v]);
        }
    }
    return 0;
}

int AP(int v){
    low[v] = dfs[v] = t;
    t++;
    for
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int num_places;
        cin >> num_places;
        if(num_places == 0){
            break;
        }
        visited.resize(num_places+1,0);
        adj.resize(num_places+1);
        string line;
        split(line, ' ');

        

        
    }
}