#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >>n;
    vector<pair<int, string>> id_vector(n);
    for(int i = 0; i < n; i++){
        int id;
        cin >> id;
        string name;
        cin.ignore();
        getline(cin, name);
        id_vector[i] = make_pair(id, name);
    }
    sort(id_vector.begin(), id_vector.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second < b.second;
    });

    for (int i = 1; i <= n; i++){
        if(id_vector[i-1].second == id_vector[i].second){
            if (id_vector[i-1].first < id_vector[i].first){
                cout << id_vector[i-1].first << " " << id_vector[i-1].second << endl;
            }else{
                cout << id_vector[i].first << " " << id_vector[i].second << endl;
                id_vector[i].first = id_vector[i-1].first;
                id_vector[i].second = id_vector[i-1].second;
            }
        }else{
            cout << id_vector[i-1].first << " " << id_vector[i-1].second << endl;
        }
    }
}