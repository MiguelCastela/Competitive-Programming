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
int DFS(int u, vector<int> &visited, vector<vector<int> > &adj){
    visited[u] = 1;
    for(int v = 0; v < adj[u].size(); v++){
        if(visited[adj[u][v]] == 0){ 
            DFS(adj[u][v], visited, adj);
        }
    }
    return 0;
}

int main(){
    set<int> poistions;
    pair<int, int> start;
    while(cin >> start.first >> start.second){
        int moves;
        cin >> moves;
        for(int i =0; i<moves; i++){
            int move 1 = start

        }
        
    }

