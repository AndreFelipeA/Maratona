#include <bits/stdc++.h>
using namespace std;
using ll = long long;

unordered_map<long long, long long> dp;

long long func(long long n)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp.find(n) != dp.end())
    {
        return dp[n];
    }

    long long val1 = func(n/2);
    long long val2 = func(n/3);
    dp[n] = val1 + val2;

    return dp[n];
}

int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}