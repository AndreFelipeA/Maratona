#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+15;
#define NEUTRAL 1


ll OP(ll x, ll y)
{
    x = x > 0 ? +1 : x < 0 ? -1 : 0;
    y = y > 0 ? +1 : y < 0 ? -1 : 0;
    return x * y;
}


vector<ll> t (2*N);
ll op_inclusive(ll l, ll r)
{
    r++;
    ll left = NEUTRAL, right = NEUTRAL;
    for (l += N, r += N; l < r; l /= 2, r /= 2) 
    {
        if (l & 1) left = OP(left, t[l++]);
        if (r & 1) right = OP(right, t[--r]);
    }
    return OP(left, right);
}


void set_value(ll i, ll v)
{
    t[i += N] = v;
    for (i /= 2; i > 0; i /= 2)
        t[i] = OP(t[i*2], t[i*2+1]);
}

void build(vector<ll>& src)
{
    for (ll i = 1; i < src.size(); i++)
        t[N+i] = src[i];
    for (ll i = N - 1; i > 0; i--)
        t[i] = OP(t[2*i], t[2*i+1]);
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n,m; 
    cin >> n >> m; 

    vector<ll> src (n+1);

    for (ll i = 1; i <= n; i++) { cin >> src[i]; }
    build(src);

    char op; 
    ll a,b;
    string s;

    while(m--) 
    {
        cin >> op;
        if(op == 'A')
        {
            cin >> a >> b;
            set_value(a,b);
        }
        if(op == 'B')
        {
            cin >> a >> b;
            ll x = op_inclusive(a,b);
            if(x == 0)
            {
                cout << x;
            }
            if(x > 0)
            {
                cout << "+";
            }
            if(x < 0)
            {
                cout << "-";
            }
        }
        else
        {
            getline(cin, s);
        }
    }
    cout << "\n";
}