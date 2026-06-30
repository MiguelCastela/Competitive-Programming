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

void DFS(string u, map<string, vector<string> > &dependencies, map<string, int> &altered, vector<string> &result){
    if(altered[u] == 1){
        return;
    }
    altered[u] = 1;

    for(int i=0; i<dependencies[u].size(); i++){
        DFS(dependencies[u][i], dependencies, altered, result);
    }
    result.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num_rules;
    cin >> num_rules;
    cin.ignore();
    map<string, vector<string> > dependencies;

    for(int i=0; i<num_rules; i++){
        string line;
        getline(cin, line);
        vector<string> tokens = split(line, ' ');
        string file = tokens[0].substr(0, tokens[0].find(':'));
        vector<string> deps(tokens.begin() + 1, tokens.end());
        dependencies[file] = deps;
    }

    string changed_file;
    cin >> changed_file;
    map<string, int> altered;
    vector<string> result;
    DFS(changed_file, dependencies, altered, result);


    reverse(result.begin(), result.end());
    for(int i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}


