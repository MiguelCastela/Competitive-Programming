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
    int sock_num;
    int capacity;
    int max_color_diff;


    cin >> sock_num >> capacity >> max_color_diff;
    vector<int> socks;
    for(int i=0; i<sock_num; i++){
        int sock;
        cin >> sock;
        socks.push_back(sock);
    }
    /*
    for(int i=0; i<sock_num; i++){
        cout << socks[i] << " ";
    }
    */
    int curr = 0;
    int counter = 0;
    int washing_machines = 1;

    sort(socks.begin(), socks.end());


    for(int i=0; i<sock_num; i++){
        if(abs(socks[curr] - socks[i]) <= max_color_diff){
            if(counter >= capacity){
                washing_machines++;
                curr = i;
                counter = 1;
            }else{
                counter++;
            }
        }else {
            washing_machines++;
            curr = i;
            counter = 1;
        }
    }
    cout << washing_machines << endl;
}