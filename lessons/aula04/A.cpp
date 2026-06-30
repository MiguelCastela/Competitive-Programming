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

bool rec(vector<vector<string> > &lines, int i, int j, int ii, int jj) {
    i += ii;
    j += jj;
    if (i < 0 || i >= 8 || j < 0 || j >= 8){
        return true;
    }
    if(lines[i][j] == "*"){
        return false;
    }
    return rec(lines,i,j,ii,jj);
    }
   
bool check_directions(vector<vector<string> > &lines,int i, int j){
    return rec(lines,i,j,1,1) && 
    rec(lines,i,j,1,0) &&
    rec(lines,i,j,1,-1) &&
    rec(lines,i,j,-1,-1) &&
    rec(lines,i,j,-1,0) &&
    rec(lines,i,j,-1,1) &&
    rec(lines,i,j,0,1) &&
    rec(lines,i,j,0,-1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    vector<vector<string> > lines(8, vector<string>(8));
    bool flag = false;
    int num = 0;

    for (int l = 0; l< 8; l++){
        cin >> s;
        for (int i = 0 ; i < 8; i++){
            lines[l][i] = s[i];
        }
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(lines[i][j] == "*"){
                num ++;
                if(!check_directions(lines,i,j)){
                    bool flag = true;
                    cout << "invalid\n";
                    return 0;
                }
            }
        }
    }
    if (num == 8){
        cout << "valid\n";
        return 0;
    }else{
        cout << "invalid\n";
        return 0;
    }
    return 0;
}
