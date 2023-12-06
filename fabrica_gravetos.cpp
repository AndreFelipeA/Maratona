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
    ll media =0;
    ll div = 0;
    for(int i=0; i< n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    ll mediana = 0;
    if(n % 2 == 0)
    {
        mediana = (v[n/2]+v[(n/2)-1])/2;
    }
    else
    {
        mediana = v[n/2];
    }

    ll soma = 0;
    for(int i=0; i< n; i++)
    {
        soma += abs(v[i] - mediana);
    }

    cout << soma << "\n";
}