#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> v;
    vector<ll> vector;    
    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if(v.size() == 0)
        {
            v.push_back(x);
            continue;
        }

        auto it = upper_bound(v.begin(), v.end(), x);
        //         cout << "Numero:"<< x << " "  << *it<< "\n";
        // cout << "it - v.begin(): " << it - v.begin() << "\n";
        // cout << v[it-v.begin()] << "\n";
        if(*it < x)
        {
            v.push_back(x);
        }
        else
        {
            v[it-v.begin()] = x;

        }

    }

    cout << v.size() << "\n";

}