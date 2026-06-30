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


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string object_price;
    string object_weight;
    int intervals;
    cin >> intervals;
    int cnt = 1;
    int curr =0;


    vector<int> bounds;
    vector<vector<int> > bounds_vec;

    for(int i=0; i<intervals;i++){
        int lower_bound;
        int upper_bound;
        cin >> lower_bound >> upper_bound;
        bounds.push_back(lower_bound);
        bounds.push_back(upper_bound);
        bounds_vec.push_back(bounds);
        bounds.clear();
    }
    sort(bounds_vec.begin(), bounds_vec.end(), greater<vector<int> >());

    curr = bounds_vec[0][0];
    for(int i=0; i<intervals; i++){
       if(curr >= bounds_vec[i][1]){
              cnt++;
              curr = bounds_vec[i][0];
       }
    }
    cout << cnt << endl;



}