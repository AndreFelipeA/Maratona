#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{ 
    int t; 
    cin >> t;

    while(t--){
        ll n, d;
        cin >> n >> d;

        vector<ll> v;

        ll aux;
        while(n%d > 0)
        {
            v.push_back(n/d);
            aux = n%d;
            n = d;
            d = aux;
        }
        v.push_back(n/d);
        aux = n%d;
        n = d;
        d = aux;
        for(int i = 0; i < v.size(); i++)
        {
            if(v.size() == 1)
            {
                cout << "[" << v[i] << "]";
                break;
            }
            if(i == 0)
            {
                cout << "[" << v[i] << ";";
                continue;
            }
            if(i == v.size()-1)
            {
                cout << v[i] << "]";
            }
            else
            {
                cout << v[i] << ",";
            }

        }
        cout << "\n";
    }
}