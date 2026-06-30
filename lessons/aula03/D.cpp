#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;

long long int binomialCoeff(int n, int k)
{
    int C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;

            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main(){
    long long int num;
    cin >> num;
    long long int first;
    long long int second;
    for(int i = 0; i < num; i++){
        cin >> first >> second;
        cout << binomialCoeff(first, second-1) << endl;
    }
}