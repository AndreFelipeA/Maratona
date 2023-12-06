#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using us = unsigned short;
long long oo = 9223372036854775807;

unsigned short n;
vector<ll> v;

ll opt = oo;

void gen(us i, vector<bool> b)
{
    if (i == n)
    {
        vector<ll> xs(n, 0);
        us c = 0;
        bool last = false;
        for (us i = 0; i < n; i++)
        {
            if (b[i] == !last)
            {
                c++;
            }
            xs[c] |= v[i];
        }
        ll s = 0;
        for (auto x : xs)
        {
            s ^= x;
        }

        if (s < opt)
        {
            opt = s;
        }
        return;
    }

    gen(i + 1, b);
    if (i > 0)
    {
        b[i] = true;
        gen(i + 1, b);
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    v.resize(n);
    for (auto &a : v)
    {
        cin >> a;
    }

    vector<bool> b(n, false);
    gen(0, b);
    cout << opt;
    cout << "\n";
}