#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(1e6, false);
vector<vector<int>> grafo(1e6);

int dist(int nodo){
    int maior = 0;
    for(int filho: grafo[nodo])
        if(!visited[filho])
        {
            visited[filho] = true;
            maior = max(maior, 1+dist(filho));
        }

    return maior;
}

int depth = 0;
int bfs(int u){
    int c = 0;
    queue<int> q;
    q.push(u);
    q.push(-1);

    while (!q.empty()){
        u = q.front(); q.pop();

        if(u == -1){

            q.push(-1);
            if(q.front() == -1)
                break; // visitou tudo

            depth++;
            continue;   
        }

        for (int v : grafo[u]) if (!visited[v]) 
        {
            c = v;
            visited[v] = true;
            q.push(v);
        }
    }
    return c;
}

int main() 
{
    int n, a, b;
    cin >> n;

    for(int i = 1; i < n; i++){
        cin >> a >> b;
        grafo[a].push_back(b); 
        grafo[b].push_back(a);
    }

    visited[1] = true;
    int pto = bfs(1); 

    visited.assign(n, false);
    visited[pto] = true;

    depth = 0;
    bfs(pto);

    cout << depth << '\n';

    
    return 0;
}