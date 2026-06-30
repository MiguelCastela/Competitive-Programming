#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int main(){
    int T; 
    cin >> T;
    for(int i= 0; i<T ; i++){
        int n;
        cin >>n;
        vector<pair<int, pair<int, int>>> a;
        for(int j = 0; j < n; j++){
            int y, xi, xf;
            cin >> y >> xi >> xf;
            a.push_back({y, {xi, xf}});
        }
        sort(a.begin(), a.end(), greater<pair<int, pair<int, int>>>());

        int current = a[0].second.second;
        int counter = 1;
        for(int j = 1; j < n; j++){
            if(a[j].second.first <= current && a[j].second.second > current){
                counter++;
                current = a[j].second.second;
            }
        }
        cout << counter << endl;
    }
}