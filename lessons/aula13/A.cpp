#include <bits/stdc++.h>
#include <string>

using namespace std;


int main(){
    int n;
    cin >> n;
    set<string> s;
    vector<string> arr;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        for(int j=0; j<x; j++){
            string t;
            cin >> t;
            arr.push_back(t);            
        }
        bool flag = false;
        sort(arr.begin(), arr.end());
        for(int j=0; j<arr.size(); j++){
            for(int k=0; k<(int)arr[j].size(); k++){
                if(s.find(arr[j].substr(0, k)) != s.end()){
                    flag = true;
                    break;
                }
            }
            s.insert(arr[j]);
        }
        s.clear();
        arr.clear();
        if(flag){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }

    }

}