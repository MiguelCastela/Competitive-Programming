#include <bits/stdc++.h>
using namespace std;

int backtrack(vector<int>& time, vector<vector<int>>& dp ,int i, int sum1, int total_sum){
    int n = time.size();
    if (i == n){
        int sum2 = total_sum - sum1;
        return abs(sum1 - sum2);
    }
    if (dp[i][sum1] != -1){
        return dp[i][sum1];
    }

    int first_oven = backtrack(time, dp, i+1, sum1 + time[i], total_sum);

    int second_oven = backtrack(time, dp, i+1, sum1, total_sum);


    return dp[i][sum1] = min(first_oven, second_oven);




}


int main(){
    int num;
    while(cin >> num ){
        vector<int> time(num);
        for (int i = 0; i<num; i++){
            int x;
            cin>>x;
            time[i] = x;
        }
        sort(time.rbegin(), time.rend());
        int total_sum = accumulate(time.begin(), time.end(), 0);
        vector<vector<int>> dp(num, vector<int>(total_sum +1, -1));
        int minimum_difference = backtrack(time, dp, 0, 0, total_sum);
        cout<<minimum_difference<<endl;
        }
    }
