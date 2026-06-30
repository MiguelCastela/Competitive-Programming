
#include <bits/stdc++.h>

using namespace std;

    vector<int> split(const string &s, const char delimiter) {
        vector<int> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(stoi(token));
        }
        return tokens;
    }
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        string s;
        set<int> diff;
        int size = 0;
        bool flag;
        vector<int> words;
        while (getline(cin, s)) {
            words.clear();
            diff.clear();
            words = split(s, ' ');
            flag = true;
            for (int i = 1; i < words[0]-1 ; i++){
                size = diff.size();
                diff.insert(abs(words[i+1]) - words[i]);
                if(diff.size() == size || abs(words[i+1] - words[i]) > words[0]-1 || abs(words[i+1] - words[i]) == 0){
                    cout << "Not jolly" << endl;
                    flag = false;
                    break;
                }
                else{
                    flag = true;
                }
            }
            if(flag){
                cout << "Jolly" << endl;
            }
        }
        return 0;
}