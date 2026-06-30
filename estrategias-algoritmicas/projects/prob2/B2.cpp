#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> parent(1001);
vector<int> ranku(1001, 0);

struct Edge {
    int u, v;
    int dist;
};

bool compareEdges(Edge& a, Edge& b) {
    return a.dist < b.dist;
}

void initUnionFind( int size) {
    for (int i = 0; i < size; ++i)
        parent[i] = i;
}

int find( int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void unite(int i, int j) {
    int first = find(i);
    int second = find(j);
    if (first != second) {
        if (ranku[first] < ranku[second]) {
            parent[first] = second;
        } else {
            parent[second] = first;
            if (ranku[first] == ranku[second])
                ranku[first]++;
        }
    }
}


bool checkMandatory(const vector<int>& mandatory) {
    int root = find(mandatory[0]);
    for (int node : mandatory) {
        if (find(node) != root)
            return false;
    }
    return true;
}

int solve(int N, const vector<Edge>& edges, const vector<int>& mandatory) {
    initUnionFind(N);

    for (const Edge& e : edges) {
        unite(e.u, e.v);
        if (checkMandatory(mandatory)) {
            return e.dist;
        }
    }

    return -1;
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

        int result = solve(N, edges, mandatory);
        if (result == -1){
            cout << "Impossible to connect!" << endl;
        }else{
            cout << result << endl;
        }
    }

    return 0;
}
