#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> pre(string ne) {
int n = ne.size();
vector<int> pi (n, 0);
for (int i = 1, j = 0; i < n; i++) {
while (j > 0 && ne[i] != ne[j]) { j = pi[j-1]; }
if (ne[i] == ne[j]) { j++; }
pi[i] = j;
}
return pi;
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s = "teste";
    
}