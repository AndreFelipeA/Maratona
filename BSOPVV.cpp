#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;

    cin >> n;

    ll count = 0;
    for(ll a =1; a <= (n/3); a++)
    {
        for(ll b = a; b < n; b++)
        {
            ll c = n - a - b;
            if(c>= b && a + b + c == n)
            {
                count++;
            }
        }
    }

    cout << count << "\n";
}