 #include <bits/stdc++.h>
 #include <unordered_map>

using namespace std;
vector<string> split(const string &s, const char delimiter) {
vector<string> tokens;
string token;
istringstream tokenStream(s);
while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
}
return tokens;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    int ones_max = 0;
    int zeros_max = 0;
    int ones = 1;
    int zeros = 1;
    cin >> num;
    vector<int> nums;
    string s;
    while (cin >> s) {
        nums.push_back(stoi(s));
    }
    
    for (int i = 1; i < num; i++) {
        if(nums[i] == 1){
            if(nums[i] == nums[i-1]){
                ones++;
            }else{
            if (ones > ones_max){
                ones_max = ones;
            }
            ones = 1;
        }
        }
        if(nums[i] == 0){
            if(nums[i] == nums[i-1]){
                zeros++;
            }else{
            if (zeros > zeros_max){
                zeros_max = zeros;
            }
            zeros = 1;
        }
        }
    }
    if (ones > ones_max){
        ones_max = ones;
    }
    if (zeros > zeros_max){
        zeros_max = zeros;
    }
    cout << ones_max << " " << zeros_max << endl;
}