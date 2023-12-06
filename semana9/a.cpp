#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4+15;

vector<int> rep (N);
vector<int> rnk (N);
vector<int> siz (N, 1);
int ds_find(int u) {
if (rep[u] != u) { rep[u] = ds_find(rep[u]); }
return rep[u];
}
void ds_union(int u, int v) {
u = ds_find(u); v = ds_find(v);
assert(u != v);
if (!(rnk[u] > rnk[v])) { swap(u, v); }
if (rnk[u] == rnk[v]) { rnk[u]++; }
rep[v] = u;
siz[u] += siz[v];
}

int main() 
{

    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    for(int j =0; j < k; j++)
    {
        int u,v;
        cin >> u >> v;
        
        for(int i=1; i<=n; i++)
        {
            if(visited[i] == false)
            {
                component++;
                explore(i);
            }

        }
        cout << component << "\n";
    }



    
}