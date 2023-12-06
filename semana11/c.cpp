#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5+15;
using ii = pair<int, int>;
int tk = 0; vector<int> tin (N, -1), low (N);
int brid = 0;

vector<vector<int>> g (N);

void dfs(int u, int p) 
{
    tin[u] = low[u] = ++tk; int ch = 0;

    for (int v : g[u]) if (v != p) 
    {
        if (tin[v] == -1) 
        {
            dfs(v, u); ch++;
            if (low[v] > tin[u])
                brid++;
            low[u] = min(low[u], low[v]);
        } 
        else 
        { 
            low[u] = min(low[u], tin[v]); 
        }
    }
}

int main() 
{
  

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int u = 1; u <= n; u++)
        {
            dfs(u,u);
        }

        cout << brid << endl;
        brid = 0;
        for(auto &u: g)
        {
            u.clear();
        }
        low.clear();
        tk =0;
        tin.assign(N,-1);
    }
    
}