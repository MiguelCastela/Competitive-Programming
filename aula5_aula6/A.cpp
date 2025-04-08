
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
int num_left(int pos, int jump,int num, vector<int> &cost, vector<vector<int> > &mem){
    if (pos<1 || pos>num){
        return numeric_limits<int>::max();
    } 
    if (pos == num){
        return cost[pos];
    }
    if (mem[pos][jump] == -1){
        mem[pos][jump] = min(num_left(pos-jump ,jump , num, cost, mem), num_left(pos + jump + 1, jump +1, num, cost, mem));
        if (mem[pos][jump] != numeric_limits<int>::max()){
            mem[pos][jump] += cost[pos];
        }
    }
    return mem[pos][jump];
}
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