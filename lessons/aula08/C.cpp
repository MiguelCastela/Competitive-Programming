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

    long long int num_fish;
    long long int num_fishmongers;
    vector<long long int> weight;
    pair<long long int, long long int> fishmonger;
    vector<pair<long long int, long long int> > fishmongers;


    cin >> num_fish >> num_fishmongers;

    for (int i =0; i<num_fish; i++){
        long long int w;
        cin >> w;
        weight.push_back(w);
    }
    
    for (int i =0; i<num_fishmongers; i++){
        long long int n_fish;
        long long int monies;
        cin >> n_fish >> monies;
        fishmonger.second = n_fish;
        fishmonger.first = monies;
        fishmongers.push_back(fishmonger);
    }

    sort(weight.begin(), weight.end(), greater<long long int>());
    sort(fishmongers.begin(), fishmongers.end(), greater<pair<long long int, long long int> >());
    


    long long int monies = 0;
    long long int curr = 0;

    for(int i=0; i<num_fish; i++){
        monies += weight[i] * fishmongers[curr].first;
        fishmongers[curr].second--;
        if(fishmongers[curr].second == 0){
            curr++;
        }
    }
    cout << monies << endl;
}