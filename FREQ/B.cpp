#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> id_vector(n);
    for(int i = 0; i < n; i++){
        int xi, xf;
        cin >> xi >> xf;
        id_vector[i] = make_pair(xi, xf);
    }
    sort(id_vector.begin(), id_vector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }); 

    int count = 0;
    int temp = 0;
    for (int i = 0; i < n; i++){
        if(id_vector[i].first >= temp){
            count++;
            temp = id_vector[i].second;
        }else if(id_vector[i].second < temp){
            temp = id_vector[i].second;
        }
    }


    cout << count << endl;
}

