#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    // cin.tie(0);
    // ios_base::sync_with_stdio(0);

    ll n;

    cin >> n;

    ll count = 0;
    for(ll i=0; i < (n/3); i++)
    {
        for(ll j = 1; j < ((n-i)/2); j++)
        {
            cout << j;
            count++;
        }
    }

    cout << count << "\n";
}