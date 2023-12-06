#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ll> v;
    map<ll,ll> m;
    pair<ll, ll> bestQuo;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    // v crescente
    sort(v.begin(), v.end());


    ll quo ;
    for(int i=1; i< n; i++)
    {
        quo = v[i]/v[i-1];
        m[quo] = (m.find(quo) == m.end()) ? 1 : m[quo]+1;
        bestQuo = (bestQuo.second < m[quo]) ? make_pair(quo, m[quo]) : bestQuo;
        
    }

    // ponta
    if(bestQuo.second == n-1)
    {
        ll first = v[0]/bestQuo.first;
        if(first != v[0] && first*bestQuo.first*bestQuo.first == v[1])
        {
            cout << v[0]/bestQuo.first << "\n";
        }
        cout << v[n-1]*bestQuo.first << "\n";
    }

    //meio
    for(int i = 1; i < n; i++)
    {
        quo = v[i]/v[i-1];
        if(quo != bestQuo.first)
        {
            cout << v[i-1]*bestQuo.first<< "\n";
            return 0;
        }
    }

    

}