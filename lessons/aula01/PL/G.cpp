#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    string name;
    float heartbeat;
    float num = 0;
    float avg = 0;

    while(getline(cin, s)){         
        string aux;
        stringstream ss(s);
        while(getline(ss, aux, ' ')){
            bool isNumber = true;
            for(char c : aux){
                if(!isdigit(c) && c != '.'){
                    isNumber = false;
                    break;
                }
            }
            if (isNumber) {
                heartbeat += stoi(aux);
                num ++;  
            } else {
                name += aux + " ";
            }
        }
        avg = heartbeat/num;
        cout << avg << " "<< name << endl;
        heartbeat = 0;
        num = 0;
        name = "";
        avg = 0;
    }
    
    return 0;
        
}
