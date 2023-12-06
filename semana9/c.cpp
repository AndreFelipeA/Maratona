#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 250; const int oo = 987654321;
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

    int n,m,c,k;
    cin >> n >> m >> c >>k;
    for(int i = 0; i < m; i++)
    {
        int u,v,p;
        cin >> u >> v >> p;


        if(((u+1 == v) || (v+1 == u)) && u < c && v < c)
        {
            cout << u << v << "p"<< "\n";
            g[u].push_back(edge(v, p));
            g[v].push_back(edge(u, p));

        }
        else if(c == u || c == v)
        {
            cout << u << v << "\n";
            g[u].push_back(edge(v, p));
            g[v].push_back(edge(u, p));
        }
    }

    dijkstra(k,c-1);


    for(int i = 0; i < n; i++)
    {

    // cout << d[i] << "\n";
    }

    cout <<"resposta: " << d[c-1] << "\n";


}