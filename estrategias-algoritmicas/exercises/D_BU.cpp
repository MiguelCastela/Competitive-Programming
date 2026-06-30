#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int lvls;
        cin >> lvls;

        vector<vector<int>> ski(lvls, vector<int>(lvls));

        // Input the triangle values
        for (int i = 0; i < lvls; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> ski[i][j];
            }
        }

        // Bottom-up DP: Start from the second-last row and move upwards
        for (int i = lvls - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                ski[i][j] += max(ski[i + 1][j], ski[i + 1][j + 1]);
            }
        }

        // The top element now contains the max path sum
        cout << ski[0][0] << endl;
    }
}
