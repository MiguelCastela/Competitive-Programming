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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num_houses;
    int num_cables;
    cin >> num_houses >> num_cables;
    vector <int> visited(num_houses+1,0);
    vector <vector<int> > adj(num_houses+1);
    for(int i=0; i<num_cables; i++){
        int house1,house2;
        cin >> house1 >> house2;
        adj[house1].push_back(house2);
        adj[house2].push_back(house1);
    }    
    DFS(1, visited, adj);
    int count = 0;
    for(int i=1; i<=visited.size()-1; i++){
        if(visited[i] == 1){
            count++;
        }else{
            cout << i << endl;
        }
    }
    if(count == num_houses){
        cout << "Connected" << endl;
    }
} 
 