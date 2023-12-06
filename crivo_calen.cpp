#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count(vector<ll> a, ll m, ll n)
{
    ll odd = 0, even = 0;
    ll counter, i, j, p = 1;
    ll pow_set_size = (1 << n);
 
    for (counter = 1; counter < pow_set_size; counter++) {
        p = 1;
        for (j = 0; j < n; j++) {
 

            if (counter & (1 << j)) {
                p *= a[j];
            }
        }

        if (__builtin_popcount(counter) & 1)
            odd += (m / p);
        else
            even += (m / p);
    }
 
    return odd - even;
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    ll A, B, n;

    cin >> A >> B >> n; 

    vector<ll> primes;
    for(int i=0; i<n;i++)
    {
        ll x;
        cin >> x;
        primes.push_back(x);
    }

    long long sum = B - A + 1;
    sum -= count(primes, B, n);
    sum += count(primes, A-1, n);  

    cout << sum << "\n";
}