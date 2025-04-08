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
    for(int i = 0; i < num; i++){
        int num_output;
        int range;
        int addition=0;
        int addition_odd=0;
        int addition_even=0;
        cin >> num_output >> range;
        addition = (range*(range+1))/2;
        addition_even = (range*(range+1));
        addition_odd = (range*range);
        cout << num_output << " " << addition << " " << addition_odd<< " " << addition_even << endl;
    }
    return 0;
}


