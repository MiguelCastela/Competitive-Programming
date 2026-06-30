
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
int num_left(int pos, int jump,int num, vector<int> &cost, vector<vector<int> > &mem){}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int num;
    cin >> num;
    vector<int> cost(num + 1);
    vector<vector<int> > nem(num + 1, vector<int>(num + 1, -1));

    for (int l = 1; l < num+1; l++){ 
        cin >> s; 
        cost[l] = stoi(s);
    }
    cout << num_left(2, 1, num, cost, nem) << endl;
   
}