#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 15;
vector<vector<int>> g(N);   // Adjacency list representation
vector<set<int>> cg (N);
vector<int> vis (N); int cts = 1;
int tk = 1; vector<int> tin (N, -1), low (N);
stack<int> st; vector<int> rep (N), onst (N);
void dfs_tarjan(int u) {
if (tin[u] != -1) { return; }
tin[u] = low[u] = onst[u] = ++tk;
st.push(u);
for (int v : g[u]) {
dfs_tarjan(v);
if (onst[v]) low[u] = min(low[u], low[v]);
}
if (low[u] == tin[u]) {
int v; do {
v = st.top(); st.pop(); onst[v] = 0;
rep[v] = u;
} while (u != v);
}
}
void tarjan(int n) {
for (int u = 0; u < n; u++) { dfs_tarjan(u); }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // g.resize(n); // Resize the graph to accommodate 'n' nodes

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        // u--;
        // v--;
        g[u].push_back(v);

    }
    tarjan(n);
    // printGraph(g);

        for (int u = 0; u < n; u++)
        for (int v : g[u]) if (rep[u] != rep[v])
        cg[rep[u]].insert(rep[v]);
        for (int u = 0; u < n; u++) if (rep[u] == u) {
        for (int v : cg[u])
        cout << u << " " << v << "\n";
        }

}
