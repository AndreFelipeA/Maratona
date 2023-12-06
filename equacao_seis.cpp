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
    map<ll,int> m;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }


    for(int i =0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ll p = v[i]*v[j] + v[k];

                m[p]++;


            }
            
        }
        
    }

    ll count = 0;
    for(int i =0; i < n; i++)
    {
        if(v[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {

                ll p = v[i]*(v[j]+v[k]);
                if(m.find(p) != m.end())
                {
                    count += m[p];
                }
            }
            
        }
        
    }

    cout << count << "\n";
}
