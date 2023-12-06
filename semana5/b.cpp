#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll moedas[] = {1, 5, 10, 25, 50};

const int x = 3e4;

vector<ll> dp(x);

void max(ll N) {
    dp[0] = 1;
    for (ll i = 0; i < 5; i++) {
        for (ll j = moedas[i]; j <= N; j++) {
            dp[j] += dp[j - moedas[i]];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> N;
    ll aux;
    while (cin >> aux) {
        N.push_back(aux);
    }
    aux=N[0];
    for(int i=1;i<N.size();i++){
        if(N[i]>aux){
            aux=N[i];
        }
    }
    
    max(x);
    
    for(int i=0;i<N.size();i++){
        cout << dp[N[i]] << endl;
    }

    return 0;
}