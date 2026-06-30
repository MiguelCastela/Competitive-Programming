#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    string s;
    cin >> num;
    cin >> s;
    string cur = "";
    int biggest = 0;
    for (int i = 0; i< num; i++){
        if (s[i] >= '0' && s[i] <= '9'){
            cur += s[i];
        } else {
            if (!cur.empty() && stoi(cur) > biggest){
                biggest = stoi(cur);
            }
            cur = "";  
        }
    }
    if (!cur.empty() && stoi(cur) > biggest) {
        biggest = stoi(cur);
    }
    cout << biggest << endl;
}