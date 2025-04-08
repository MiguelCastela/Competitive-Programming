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
        int num;
        cin >> num;
        vector<string> words;
        set<string> words_set;
        string s;
        bool flag = false;
        while (cin >> s) {
            words.push_back(s);
        }
        words_set.insert(words[0]);
        for (int i = 1; i < num; i++) {
            if (words[i][0] != words[i-1][words[i-1].size() -1]){
                flag = true;
                if (i % 2 == 0){
                    cout << "Player 1 lost" << endl;
                } else {
                    cout << "Player 2 lost" << endl;
                }
                break;
                }
            if (words_set.find(words[i]) != words_set.end()){
                flag = true;
                if (i % 2 == 0){
                    cout << "Player 1 lost" << endl;
                } else {
                    cout << "Player 2 lost" << endl;
                }
                break;
            }
            words_set.insert(words[i]);
        }
        if (!flag){
            cout << "Fair Game" << endl;
        }
    return 0;
    }