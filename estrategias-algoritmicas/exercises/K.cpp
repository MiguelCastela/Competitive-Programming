#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

struct Edge {
    int u, v;
    double dist;
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
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unite(vector<int>& parent, int i, int j) {
    int first = find(parent, i);
    int second = find(parent, j);
    if (first != second)
        parent[first] = second;
}

double euclideanDistance(Point& a, Point& b) {
    return sqrt((abs(a.x - b.x) * abs(a.x - b.x) + abs(a.y - b.y) * abs(a.y - b.y)));
}

double kruskalTree(vector<Edge>& edges, vector<int>& parent) {
    double totalCable = 0.0;
    for (auto& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            unite(parent, edge.u, edge.v);
            totalCable += edge.dist;
        }
    }
    return totalCable;
}


int main() {
    int n;
    while (cin >> n) {
        vector<Point> points(n);
        for (int i = 0; i < n; ++i){
            cin >> points[i].x >> points[i].y;
        }

        int m;
        cin >> m;

        vector<int> parent;
        initUnionFind(parent, n);

        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            unite(parent, a-1, b-1); 
        }

        vector<Edge> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = euclideanDistance(points[i], points[j]);
                edges.push_back({i, j, dist});
            }
        }

        sort(edges.begin(), edges.end(), compareEdges);
        double totalCable = kruskalTree(edges, parent);
        printf("%.2lf\n",totalCable);
    }
}
