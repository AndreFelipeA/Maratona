#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll swaps = 0;
vector<ll> a(1e5+15);
ll merge_sort(ll l, ll r)
{
    if (r - l == 1 || r == 0)
    {
         return swaps; 
    }
    ll mi = l + (r - l) / 2;
    merge_sort(l, mi); merge_sort(mi, r);
    vector<ll> aux (r - l);
    ll i = l, j = mi;
    for (ll k = 0; k < r - l; k++) 
    {
        if (i < mi && j < r) 
        {
            if (!(a[i] < a[j]))
            { 
                swaps += mi - i; 
            }
            if (a[i] < a[j]) 
            {
                aux[k] = a[i++];
            }
            else 
            { 
                aux[k] = a[j++];
            }
        }
        else if (i < mi) 
        { 
            aux[k] = a[i++];
        }
        else 
        { 
            aux[k] = a[j++];
         }
    }
    copy(aux.begin(), aux.end(), a.begin()+l);

    return swaps;
}



int main()
{
    ll n, h;
    cin >> n >> h;
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> a[i];
    }

    vector<ll> v;
    v.assign(a.begin(), a.begin()+h);

    ll count  = merge_sort(0,n);

    swaps = 0;
    a.assign(v.begin(), v.end());
    swaps = merge_sort(0,h);

    cout << count-swaps << "\n";
    return 0;
}
