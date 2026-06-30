#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

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



int main (){  
    long long int num, target;
    cin >> num >> target;
    vector<int> values(num);
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < num; i++) {
        cin >> values[i];
    }
    sort(values.begin(), values.end(), greater<int>());


    long long int count = 0;

    for(int i=0; i<num;i++){
        if(values[i] > target){
            continue;
        }
        if(target == 0){
            break;
        }
        count += target/values[i];
        target -= (target/values[i])*values[i];
    }

    if(target == 0){
        cout << count << endl;
    }else{
        cout << -1 << endl;
    }
    

    
    return 0;








}