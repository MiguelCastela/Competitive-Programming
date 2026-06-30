#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int num, q;
    cin >> num >> q;
    vector<long long int> a;
    vector<long long int> b;
    for(int i = 0; i < num; i++){
        long long int temp;
        cin >> temp;
        a.push_back(temp);
    }
    std::sort(a.begin(), a.end());
    for(int i = 0; i < num; i++){
        if (i > 0){
            b.push_back(a[i] + b[i-1]);
        }else{
            b.push_back(a[i]);
        }   
    }
    for(int j = 0; j < q; j++){
        long long int temp, temp2;
        cin >> temp >> temp2;
        long long int s = num-temp;
        long long int s2 = s + temp2;
            if(s > 0){ 
                cout << b[s2-1] - b[s-1] << endl;
            }else{
                cout << b[s2-1] << endl;
            }
        }
    }


