#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4+15; const int oo = 987654321;
using edge = pair<int, int>;
vector<vector<edge>> g (N);
vector<int> d (N, oo), vis (N);


void dijkstra(int src, int f) 
{
    priority_queue<pair<ll, int>,
    vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    d[src] = 0;
    Q.push({0, src});
    while (!Q.empty())
    {
        pair<ll,int> par= Q.top(); Q.pop();
        if (vis[par.second]) { continue; }
        vis[par.second] = true;
        for (auto pair: g[par.second])
        if (d[pair.first] > d[par.second] + pair.second) 
        {
            d[pair.first] = d[par.second] + pair.second;
            Q.push({d[pair.first], pair.first});
        }

    }
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n,m;
    cin >> n >> m;

    vector<vector<ll>> d (n, vector<ll>(n, oo));
    while (m--) 
    { 
        int u, v, w; 
        cin >> u >> v >> w;
        d[u][v] = w; 
        d[v][u] = w;
    }

    for (int u = 0; u < n; u++)
        d[u][u] = 0;
    for (int m = 0; m < n; m++)
    for (int u = 0; u < n; u++)
    for (int v = 0; v < n; v++)
        d[u][v] = min(d[u][v], d[u][m] + d[m][v]);

    int max = -1;
    vector<int> dist(n,0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(max < d[i][j] && d[i][j] !=987654321)
            {
                max = d[i][j];
            }
        }
        dist[i] = max;
        max = -1;

    }
    int menor = 10000;
    for(int i =0; i < n; i++)
    {
        menor = min(menor,dist[i]);
    }

    cout << menor << "\n";
}