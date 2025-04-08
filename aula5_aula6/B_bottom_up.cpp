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

int PDC_bu(int n, int v, vector<vector<int> > &matrix){
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            if(j == 0 || j == i-1){
                matrix[i][j] = 1;
            }else if(i == 0){
                matrix[i][j] = 0;
            }else{
                matrix[i][j] = ((((matrix[i-1][j-1] *(i-j)) % 1001113) + ((matrix[i-1][j]*(j+1))) % 1001113) % 1001113);
            }
        }
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
        cout << nu << " " << PDC_bu(n, v, matrix) << endl;
    }
}