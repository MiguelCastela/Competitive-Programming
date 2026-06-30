#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v;
    int dist;
};

bool compareEdges(Edge& a, Edge& b) {
    return a.dist < b.dist;
}

void initUnionFind(vector<int>& parent, int size) {
    parent.resize(size);
    for (int i = 0; i < size; ++i)
        parent[i] = i;
}

int find(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unite(vector<int>& parent, int i, int j) {
    int first = find(parent, i);
    int second = find(parent, j);
    if (first != second)
        parent[first] = second;
}

bool checkMandatory(vector<int>& parent, const vector<int>& mandatory) {
    int root = find(parent, mandatory[0]);
    for (int node : mandatory) {
        if (find(parent, node) != root)
            return false;
    }
    return true;
}

int kruskal(int N, const vector<Edge>& edges, const vector<int>& mandatory) {
    int low = 0;
    int high = edges.back().dist;
    int answer = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        vector<int> parent;
        initUnionFind(parent, N);

        for (const Edge& e : edges) {
            if (e.dist <= mid) {
                unite(parent, e.u, e.v);
            }
        }

        if (checkMandatory(parent, mandatory)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, E;
    while (cin >> N >> E) {
        vector<Edge> edges(E);
        for (int i = 0; i < E; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].dist;
        }

        int M;
        cin >> M;
        vector<int> mandatory(M);
        for (int i = 0; i < M; ++i){
            cin >> mandatory[i];
        }

        sort(edges.begin(), edges.end(), compareEdges);

        int result = kruskal(N, edges, mandatory);
        if (result == -1){
            cout << "Impossible to connect!" << endl;
        }else{
            cout << result << endl;
        }
    }

    return 0;
}
