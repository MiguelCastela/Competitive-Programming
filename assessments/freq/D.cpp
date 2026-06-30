#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<vector<pair<int64_t, int64_t>>> adj;

vector<int64_t> dijsktra(int64_t n, int64_t s)
{
    vector<int64_t> dist(n, INT64_MAX);
    dist[s] = 0;
    priority_queue<pair<int64_t, int64_t>, vector<pair<int64_t, int64_t>>, greater<pair<int64_t, int64_t>>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty())
    {
        pair<int64_t, int64_t> front = pq.top();
        pq.pop();
        int64_t d = front.first, u = front.second;
        if (d > dist[u]) {
            continue;
        }
        for (int j = 0; j < (int) adj[u].size(); j++)
        {
            pair<int64_t, int64_t> v = adj[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(make_pair(dist[v.first], v.first));
            }
        }
    }
    return dist;
}

int main(){
    int locations, roads;
    cin >> locations >> roads;
    adj.assign(locations, vector<pair<int64_t, int64_t> >());
    for(int i = 0; i< roads ; i++){
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
    }

    vector<int64_t> dist = dijsktra(0, locations);

    for(int i = 0; i < roads; i++){
        int c;
        cin >> c;
        cout << dist[c] << endl;
    }
}