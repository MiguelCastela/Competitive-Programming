#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;


int main(){

    int nodes, num;

    cin >> nodes >> num;

    vector<pair<int, int>> edges;

    for (int i = 0; i < num; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }

    int count = 0;
    bool flag = false;
    for (int i = 0; i < num; ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        for (int j = 0; j < num; ++j) {
            if (i == j) {
                continue;
            }
            int x = edges[j].first;
            int y = edges[j].second;
            if (u == x || u == y || v == x || v == y) {
                flag = true;
                break;
            }else{
                count++;
            }
        }
    }
    if (flag) {
        cout << "IMPOSSIBLE" << endl;
    }else{
        for (int i = 0; i < num; ++i) {
            cout << edges[i].first << " " << edges[i].second << endl;
        }
    }



    




}