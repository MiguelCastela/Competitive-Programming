#include <bits/stdc++.h>

using namespace std;

int main(){
    int num;
    cin >> num;
    int num_output;
    string s;
    bool flag = false;
    for(int i = 0; i < num; i++){
        flag = false;
        cin >> num_output >> s;
        //cout << num_output << s << endl;
        for (int j = 0; j < s.size() ; j++){
            if (s[j] == '8' || s[j] == '9'){
                cout << num_output<< " " << "0" << " " << stoll(s, NULL, 10) <<" " << stoll(s,NULL,16)<< endl;
                flag = true;
                break;
            }
        }
        if (flag == false){
            cout <<num_output<< " " << stoll(s, NULL, 8) <<" " << stoll(s, NULL, 10) <<" " << stoll(s,NULL,16)<< endl;
    }
}
}