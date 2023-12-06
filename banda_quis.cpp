#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binarySearch(vector<ll> arr, ll l, ll r, ll x)
{
    while (l <= r) {
        ll m = l + (r - l) / 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
        {
            return m;
        }
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n,m;
    cin >> n >> m;

    vector<ll> v;
    vector<ll> vector(m,0);
    vector<ll>::reverse_iterator rit;

    for(int i =0; i < n; i++)
    {
        ll x;
        cin >> x;
     
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        vector[i] = x;
    }

    // for(int i = 0; i < m; i++)
    // {
    //     ll x;
    //     cin >> x;
    //     ll result = binarySearch(v,0,n-1,rit);
    //     (result == -1) ? cout << -1 << "\n" : cout << result << "\n";
    //     rit++;
    // }
}