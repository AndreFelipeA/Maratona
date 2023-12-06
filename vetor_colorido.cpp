#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<ll,int>> v;
    map<int, ll> m;

    for(int i =0; i < n; i++)
    {
        ll x;
        int cor;
        cin >> x >> cor;
        if(m.find(cor) != m.end())
        {
            if(m[cor] <= x)
            {
                m[cor] = x;
            }
            else
            {
                cout << "NO" << "\n";
                return 0;
            }
        }
        else
        {
            m[cor] = x;
        }
    }

    cout << "YES" << "\n";


}