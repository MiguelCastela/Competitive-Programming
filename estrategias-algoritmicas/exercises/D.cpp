#include <bits/stdc++.h>
using namespace std;

int backtrack(vector<vector<int>>& ski, vector<vector<int>>& dp ,int i, int j) {
    int n = ski.size();

    if (i == n - 1) {
        return ski[i][j]; 
    }

    if(dp[i][j] != -1){
        return  dp[i][j];
    }

    int left = 0;
    int right = 0;
        if (i + 1 < n && j < ski[i + 1].size()) {
            int flag = ski[i+1][j];
            left = backtrack(ski,dp, i + 1, j);
        }
        if (i + 1 < n && j + 1 < ski[i + 1].size()){
            int flag = ski[i+1][j+1];
            right = backtrack(ski,dp,i + 1, j + 1);
        }

        return dp[i][j] = ski[i][j] + max(left, right);

}

int main(){
    int test;
    cin>>test;
    for (int s = 0; s<test; s++){
        int lvls;
        cin>>lvls;
        vector<vector<int>> ski;
        ski.resize(lvls);
        for (int i = 0; i<lvls; i++){
            for(int j = 0; j< i+1 ; j++){
                int x;
                cin>>x;
                ski[i].push_back(x); 
            }

        }
        vector<vector<int>> dp(lvls-1, vector<int>(lvls, -1));
        int max_points = backtrack(ski, dp, 0, 0);
        cout<<max_points<<endl;
    }
    }

