#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<vector<int> > matrix;
vector<int> weights;
vector<int> prices;

int ksbu(vector<int> &weight, vector<int> &prices, int num_objects, int max_weight_index) {
    vector<int> dp(max_weight_index + 1, 0);
    for (int i = 0; i < num_objects; i++) {
        for (int j = max_weight_index; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + prices[i]);
        }
    }
    return dp[max_weight_index];
}


int main (){  
    int n, num;
    cin >> n >> num;
    weights.assign(n, 0);
    prices.assign(n, 0);
    for (int i = 0; i < n; i++){
        cin >> weights[i] >> prices[i];

    }
    for (int s = 0; s < num; s++) {
        int max_weight_index;
        cin >> max_weight_index;
        cout << ksbu(weights, prices, n, max_weight_index) << endl;
    }
    return 0;








}