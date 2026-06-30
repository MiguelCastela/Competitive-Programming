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
vector<vector<int> > costs;
vector<int> cut;

int custo(int left, int right) {    
    if((right - left) <= 1) {
        return 0;
    }
    int costk = INT_MAX;
    if(costs[left][right] == -1) { 
        for(int k = left + 1; k < right; k++) {
            costk = min(costk, custo(left, k) + custo(k, right) + cut[right] - cut[left]);
        }
        costs[left][right] = costk; 
    }
    return costs[left][right];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int length, numCuts;
    int solve;
    cin >> length;

    while(length!=0){
        cin >> numCuts;
        cut.clear();
        cut.push_back(0);
        for (int i = 0; i < numCuts; i++){
            int cuts;
            cin >> cuts;
            cut.push_back(cuts);
        }
        cut.push_back(length);
        costs = vector<vector<int> >(numCuts+2, vector<int>(numCuts+2, -1));
        solve = custo(0, numCuts+1);
        cout << "The minimum cutting is " << solve << "." << endl;
        cin >> length;
 
    }
}










