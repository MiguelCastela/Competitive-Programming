#include <bits/stdc++.h>

using namespace std;

vector<int> split(const string &s, const char delimiter) {
        vector<int> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(stoi(token));
        }
        return tokens;
    }

int main(){
    int n;
    int rung; 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin >> n >> rung;
    vector<int> rungs;
    vector<int> result(n);
    while(cin >> s){
        rungs.push_back(s);
    }
    int current = 0;
    for (int i =1 ; i <= n; i++){
        current =i;
        for (int j = 0; j < rungs.size(); j++){
            if(current == rungs[j]){
                current = rungs[j] +1;
            }
            else if(current == rungs[j] +1){
                current = rungs[j];
            }
        }
        result[current-1] = i;
    }
for (int i = 0; i < result.size(); i++){
    cout << result[i] << endl;
}
return 0;
}