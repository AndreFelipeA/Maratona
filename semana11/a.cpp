#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+15; int cts = 1;
vector<vector<int>> g (N);

int tk = 1; vector<int> tin (N, -1), low (N);
stack<int> st; vector<int> rep (N), onst (N);
vector<set<int>> cg (N);

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

vector<int> findSinkVertices(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> sinkVertices;

    for (int v = 0; v < n; v++) {
        bool isSink = true;

        if (!graph[v].empty()) {
            isSink = false;
        }

        for (int u = 0; u < n; u++) {
            if (u != v && graph[u][v] == 0) {
                isSink = false;
                break;
            }
        }

        if (isSink) {
            sinkVertices.push_back(v);
        }
    }

    return sinkVertices;
}

void printGraph(const vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << "Adjacent nodes of " << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}


int main() 
{
     int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v); 
    }
  
    tarjan(n);
    vector<vector<int>> gc(n);
    cout << "grafo condensado \n";
    for (int u = 0; u < n; u++)
    for (int v : g[u]) if (rep[u] != rep[v])
        cg[rep[u]].insert(rep[v]);
    for (int u = 0; u < n; u++) if (rep[u] == u) 
    {
        for (int v : cg[u])
        {
            gc[u].push_back(v);
        }
    }
    printGraph(gc);

    vector<int> k = findSinkVertices(gc);
    cout << k.size() << "\n";
}