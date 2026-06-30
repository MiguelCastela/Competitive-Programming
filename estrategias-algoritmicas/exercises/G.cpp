#include <bits/stdc++.h>
using namespace std;

vector<unordered_set<int>> adj; 

void recBnb(int index, unordered_set<int> current, vector<int> remaining, int n, int &maxi) {

    if (remaining.empty()) {
        maxi = max(maxi, (int)current.size());
        return;
    }

    if (index >= n) {
        maxi = max(maxi, (int)current.size());
        return;
    }

    if (current.size() + remaining.size() <= maxi)
        return;

        

    int node = remaining.back();
    remaining.pop_back(); 

    bool Include = true;
    for (int neighbor : adj[node]) {
        if (current.count(neighbor)) {
            Include = false;
            break;
        }
    }

    if (Include) {
        current.insert(node);
        recBnb(index + 1, current, remaining, n, maxi);
        current.erase(node);
    }

    recBnb(index + 1, current, remaining, n, maxi);
    remaining.push_back(node);
}

int findLargest(int n, int &maxi) {
    unordered_set<int> current;
    vector<int> remaining;
    for (int i = 0; i < n; i++){
        remaining.push_back(i);
    }
    recBnb(0, current, remaining, n, maxi);
    return maxi;
}

int main() {
    int maxi = 0;
    int m, n;
    cin >> n >> m; 
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cout << findLargest(n, maxi) << endl;
    return 0;
}
