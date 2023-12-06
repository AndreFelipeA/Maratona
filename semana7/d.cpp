#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll constant = 1e9+7;


ll fast_pow(ll a, ll b)
{
    if (b == 0)
    { 
        return 1;
    } 
    if (b == 1) 
    { 
        return a;
    }
    ll res = fast_pow(a, b/2);
    res = (res * res) % constant;
    if (b % 2) res = (res * a) % constant;
    return res;
}

int main() {
    int T;
    cin >> T;


    ll n, aux;
    while(T--){
        cin >> n;

        if(n <= 9) {
            cout << n << '\n';
            continue;
        }

        ll remain = n;
        ll times = n / 9;
        ll rest = n % 9;


        aux = fast_pow(10, times) - 1;



        aux += rest * fast_pow(10, times);

        cout << aux % constant  << '\n';
    }

}