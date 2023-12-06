#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    char d;
    int n, a;
    stack<pair<int, char>> tower;

    int popped, maxh = -1;

    cin >> n;

    while(n--){
        cin >> a >> d;
        
        if(tower.empty())
        {
            tower.push({a, d});
            maxh = -1;
            continue;
        }

        if(tower.top().first != a || tower.top().second != 'L' || d != 'O')
        {
            tower.push({a, d});
            continue;
        }
        popped = tower.top().first;
        tower.pop();

        if(popped <= maxh)
        {
            cout << "N\n";
            return 0;
        }

        maxh = max(maxh, popped);
    }

    if(tower.empty())
    {
        cout << "S\n";
    }
    else
        cout << "N\n";

}