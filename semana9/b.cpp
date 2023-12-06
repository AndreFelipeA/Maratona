#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 15;
const int oo = 987654321;

struct edge {
    int u, v, w;
};

vector<edge> edges;
vector<int> d(N, oo);

int bellman_ford(int src, int dest, int n) {
    d[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > d[u]) continue;

        for (auto e : edges) {
            if (e.u == u && d[e.v] > d[u] + e.w) {
                d[e.v] = d[u] + e.w;
                pq.push({d[e.v], e.v});
            }
        }
    }

    return d[dest];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, l;
    cin >> n;
    vector<int> custo(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        custo[i] = p;
    }

    cin >> l;
    edges.resize(l);
    for (int i = 0; i < l; i++) {
        int u, v;
        cin >> u >> v;
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = custo[v] - custo[u];
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;
        bellman_ford(1, x, n);
        if (d[x] == oo || d[x] < 3) {
            cout << "Não, Edsger..." << endl;
        } else {
            cout << d[x] << endl;
        }
    }

    return 0;
}