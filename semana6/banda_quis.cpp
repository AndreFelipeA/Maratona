#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n,m;
    cin >> n >> m;

    multiset<ll> mset;
    
    for(int i =0; i < n; i++)
    {
        ll x;
        cin >> x;
     
        mset.insert(x);
    }

    for(int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        auto it = mset.lower_bound(x);
        if(it != mset.end() && *it == x)
        {
            cout << *it << "\n";
            mset.erase(it);
            continue;
        }
        else if(it != mset.begin())
        {
            it--;
            cout << *it << "\n";
            mset.erase(it);
            continue;
        }

         cout << -1 << "\n";


    }
}