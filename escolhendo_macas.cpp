#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;

    vector<ll> g, r, no, escolhas;
    vector<ll> chosen_g, chosen_r;

    for(int i= 0; i < a; i++)
    {
        ll p;
        cin >> p;
        r.push_back(p);
    }

    for(int i= 0; i < b; i++)
    {
        ll q;
        cin >> q;
        g.push_back(q);
    }

    for(int i= 0; i < c; i++)
    {
        ll r;
        cin >> r;
        no.push_back(r);
    }

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(no.begin(), no.end());

    for(int i =0; i <x; i++)
    {
        chosen_r.push_back(r.back());
        r.pop_back();
    }

    for(int i =0; i <y; i++)
    {
        chosen_g.push_back(g.back());
        g.pop_back();

    }


    ll red = x-1;
    ll green = y-1;
    ll noColor = 0;
    ll bigger = c-1;
    while(noColor < c)
    {
        if(red < 0 && green < 0)
        {
            break;
        }
        if(chosen_r[red] <= chosen_g[green] && no[bigger] > chosen_r[red] && red >= 0)
        {
            chosen_r[red] = no[bigger];
            noColor++;
            red--;
            bigger -= 1;
            continue;
        }
        if(chosen_g[green] <= chosen_r[red] && no[bigger] > chosen_g[green] && green >= 0)
        {
            chosen_g[green] = no[bigger];
            noColor++;
            green--;
            bigger -= 1;
            continue;
        }

        noColor++;
    }



    ll gostosuras = 0;
    for(int i =0; i <x; i++)
    {
        gostosuras+= chosen_r[i];
    }

    for(int i =0; i <y; i++)
    {
        gostosuras+= chosen_g[i];
    }

    cout << gostosuras << "\n";
}