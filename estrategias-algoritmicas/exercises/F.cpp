#include <bits/stdc++.h>
using namespace std;

int min_guards(vector<int>& positions, int dist) {
    sort(positions.begin(), positions.end()); 
    
    int guards = 0;
    int n = positions.size();
    int i = 0;

    while (i < n) {
        guards++;  
        int pos = positions[i] + dist;  
        while (i < n && positions[i] <= pos) {
            i++;
        }
        
        pos = pos + dist;
        while (i < n && positions[i] <= pos) {
            i++;
        }

    }
    return guards;
}

int main(){

    int T;
    cin >> T;
    for(int i= 0; i < T; i++){
        int n, dist;
        cin >> n >> dist;
        vector<int> positions(n);
        for (int i = 0; i < n; i++){
            int pos;
            cin >> pos;
            positions[i] = pos;
        }
        cout << min_guards(positions, dist) << endl;

    }
}