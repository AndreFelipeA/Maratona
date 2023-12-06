#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double calc_area(vector<ll> &tiras, vector<ll> &area, double cut) 
{
    int lo = 0, hi = tiras.size();
    while (lo < hi)
    {
        int mi = lo + (hi-lo) / 2;
        if (tiras[mi] >= cut) 
        { 
            lo = mi + 1;
        }
        else 
        { 
            hi = mi;
        }
    }

    int lim = lo;
    double tam_area = (lim <= 0) ? 0 : ((double) area[lim-1]) - ((lim)*cut);
    return tam_area;
}

double binarySearch(vector<ll> &tiras, vector<ll> &area, int a) 
{
    double n = 11234;
    double lo = 0, hi = n;
    while (abs(lo - hi) > 0.0000001) 
    {
        double mi = lo + (hi - lo) / 2;
        if (calc_area(tiras, area, mi) <= a) {
            hi = mi;
        } else {
            lo = mi;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n >> a;
    while (n != 0 || a != 0) 
    {
        vector<ll> tiras(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> tiras[i];
        }
        sort(tiras.begin(), tiras.end(), greater<int>());

        vector<ll> area(n);
        ll soma = 0;
        for (int i = 0; i < n; i++) 
        {
            soma += tiras[i];
            area[i] = soma;
        }

        if (area[area.size()-1] < a) 
        {
            cout << "-.-" << "\n";
        } else if (area[area.size()-1] == a)
        {
            cout << ":D" << "\n";
        } else 
        {
            cout << fixed << setprecision(4) << binarySearch(tiras, area, a) << "\n";
        }
        cin >> n >> a;
    }

    return 0;
}