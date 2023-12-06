#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> visited(10e3,false);
vector<vector<int>> graph(10e3);

int component = 0;

int explore(int u) {
int c = 0;
queue<int> q;
q.push(u);
while (!q.empty()) {
int u = q.front(); q.pop();
for (int v : graph[u]) if (!visited[v]) {
c++;
visited[v] = true;
q.push(v);
}
}
return c;
}
int dfs(int u, vector<vector<int>> g) 
{
    int c = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!visited[v])
        {
            c++;
            visited[v] = true;
            q.push(v);
        }
    }
    return c;
}

int main() 
{

    int n, m;
    cin >> n >> m;

    for(int i=0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        // graph[i].push_back(i);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    for(int i=0; i<n; i++)
    {

      
        if(visited[i] == false)
        {
            component++;
            explore(i);
        }

    }

    cout << component << "\n";


    
}