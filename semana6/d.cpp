#include <bits/stdc++.h>
using namespace std;

#define cord pair<ll, ll>
#define PN cout << "\n"
using ll = long long;

void print(vector<ll> v, string s = "")
{
    cout << s << ": ";
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

inline short dr(short a)
{
    if ((a % 9) == 0)
    {
        return 0;
    }

    while (a > 9)
    {
        short sum = 0;
        while (a > 0)
        {
            sum += (a % 10);
            a /= 10;
        }
        a = sum % 9;
    }
    return a;
}

ll n;
vector<ll> sm;
void add(ll i, ll delta)
{
    for (; i < n + 1; i += i & (-i))
        sm[i] += delta;
}
int get(ll i)
{
    ll ans = 0;
    for (; i > 0; i -= i & (-i))
        ans += sm[i];
    return ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    // code
    ll q;

    cin >> n;
    sm = vector<ll>(n + 1, 0);
    string s;

    char c;
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> c;
        s += c;
        add(i, (c - '0'));
    }
    cin >> q;


    int token = 1;

    while (q--)
    {
        ll op;
        cin >> op;

        if ((op == 1) || (op == 2))
        {
            ll a1, b1, a2, b2;
            short d;
            cin >> a1 >> b1 >> a2 >> b2 >> d;

            ll d1 = (get(b1) - get(a1 - 1));
            ll d2 = (get(b2) - get(a2 - 1));



            d1 = d1 % 9;
            d2 = d2 % 9;

            bool ans = false;
            if (op == 1)
            {
                ans = (dr(d1 + d2) == d);
            }
            else if (op == 2)
            {
                ans = (dr(d1 * d2) == d);
            }



            if (ans)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            token++;
        }
        else if (op == 3)
        {
            ll p;
            char d;
            cin >> p >> d;

            ll delta = (d - '0') - (s[p - 1] - '0');

            s[p - 1] = d;

            add(p, delta);


        }
    }
}

