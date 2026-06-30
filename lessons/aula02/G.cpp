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
    int add = 0;
    int num;
    cin >> num;
    int l = 0;
    vector<int> cards;
    string s;
    while (cin >> s) {
        cards.push_back(stoi(s));
    }
    sort(cards.begin(), cards.end());
    add += cards[0];
    for (int i = 1; i < num ; i++) {
        if (cards[i]-1 != cards[i-1]) {
            add += cards[i];
        }
    }
    cout << add << endl;
    return 0;
}

    


