#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int melhor(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.second > b.second){
        return a.second;
    }

    return b.second;
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    int n;
    cin >> n;

    vector<pair<ll,ll>> v;

    for(int i = 0; i < n; i++)
    {
        ll l,d;
        cin >> l >> d;
        v.push_back(make_pair(l,d));
    }


    sort(v.begin(), v.end(),  [ ]( const auto& lhs, const auto& rhs )
    {
        return lhs.second > rhs.second;
    });
    for(int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }


    ll litros = 0;
    cout << litros << "\n";

}