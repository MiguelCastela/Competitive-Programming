#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string abrev;
    abrev += s[0];
    for (int i = 1; i < s.size(); i++){
        if (s[i] == '-'){
            abrev += s[i+1];
        }
    }
    cout << abrev << endl;
}