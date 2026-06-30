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

int PDC(int n, int v, vector<vector<int> > &matrix){
    if(v == 0 || v == n-1){
        return 1;
    }if (matrix[n][v] == -1){
        matrix[n][v] = ((((PDC(n-1, v-1, matrix) *(n-v)) % 1001113) + ((PDC(n-1, v, matrix)*(v+1))) % 1001113) % 1001113);
    }
    return matrix[n][v];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string nu;
    int num, n , v;
    vector<vector<int> > matrix;
    cin >> num;
    matrix = vector<vector<int> >(101, vector<int>(101, -1));
    for (int l = 0; l < num; l++){ 
        cin >> nu;
        cin >> n;
        cin >> v;
        cout << nu << " " << PDC(n, v, matrix) << endl;
    }
}