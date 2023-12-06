#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int max_joy(int N, const vector<vector<int>>& a)
{
    vector<vector<int>> dp(N + 1, vector<int>(3, 0));
    for (int i = 1; i <= N; i++) {
        dp[i][0] = max(dp[i-1][1] + a[i][0], dp[i-1][2] + a[i][0]);
        dp[i][1] = max(dp[i-1][0] + a[i][1], dp[i-1][2] + a[i][1]);
        dp[i][2] = max(dp[i-1][0] + a[i][2], dp[i-1][1] + a[i][2]);
    }
    return max(dp[N][0], max(dp[N][1], dp[N][2]));
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;
    
    vector<vector<int>> a(N + 1, vector<int>(3));
    for (int i = 1; i <= N; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    
    int resultado = max_joy(N, a);
    cout << resultado << endl;

    return 0;
}