 #include <bits/stdc++.h>
 #include <unordered_map>

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
        int num;
        int min;
        int count = 0;
        cin >> num;
        vector<string> seats;
        unordered_map<string, int> seats_map;
        string s;
        bool flag = false;
        while (cin >> s) {
            seats.push_back(s);
        }
        long long min_atual = LLONG_MAX;
        for (int i = 0; i < num; i++)  {
            if (seats_map.find(seats[i]) != seats_map.end()) {
                count = i - (seats_map[seats[i]]);
                if (count < min_atual) {
                    min_atual = count;
                }
            } else {
                    seats_map[seats[i]] = i;
            }
        } 
        if (count < min_atual) {
                min_atual = num;
            }          
        cout << min_atual << endl;
        return 0;
}
