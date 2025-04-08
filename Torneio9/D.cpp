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
    string s;
    int T;
    int tele = 0;
    cin >> T;
    vector<string> locais;
    for(int i = 0; i < T; i++){
        int num_locais;
        int energia;
        cin >> num_locais >> energia;
        for(int j = 0; j < num_locais; j++ ){
            cin >> s;
            locais.push_back(s);
        }
        for(int j = 0; j < num_locais; j++){
            if (energia == 0){
                break;
            }
            energia -= 1;
            if(locais[j] != "0" && stoi(locais[j]) < energia){
                energia -= stoi(locais[j]);
                energia -= 1;
                if (energia >= 0){
                tele++;
                j = 0;
                locais[j] = "0";
                }
                else{
                    break;
                }
            }
            //cout << "energia" << energia << "tele" << tele << endl;
            }
        if (energia < 0){
            tele --;
        }
        cout << tele << endl;
        tele = 0;
        locais.clear();
    }
}