#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> subtreeSize;

int dfs(int node, int parent) {
    subtreeSize[node] = 1;
    int centroid = -1;

    for (int child : tree[node]) {
        if (child != parent && !visited[child]) {
            int childCentroid = dfs(child, node);
            if (childCentroid != -1) {
                return childCentroid;
            }
            subtreeSize[node] += subtreeSize[child];
            if (subtreeSize[child] > subtreeSize[node] / 2) {
                centroid = child;
            }
        }
    }

    if (centroid == -1 && (tree.size() - subtreeSize[node]) <= tree.size() / 2) {
        centroid = node;
    }

    return centroid;
}

int findCentroid() {
    visited.assign(tree.size(), false);
    subtreeSize.assign(tree.size(), 0);

    return dfs(1, -1);
}

int main() {
    int N;
    cin >> N;

    tree.resize(N + 1); // Índices de 1 a N

    for (int i = 1; i < N; i++) {
        int A, B;
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }

    int centroid = findCentroid();

    cout << centroid << endl;

    return 0;
}