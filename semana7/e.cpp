#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll findPoints(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int g = gcd(dx, dy);
    int x, y, i;
    return g+1;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x1, y1, x2, y2;

    int t;
    cin >> t;
    while(t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        ll count=findPoints(x1, y1, x2, y2);

        cout << count << "\n";
    }

}