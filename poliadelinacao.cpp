#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int n;
    string s;
    string a = "AAAAAAA";

    cin >> n;
    cin >> s;

    int x = s.find(a);
    if(x == -1)
    {
        cout << 0 << "\n";
        return 0;
    }

    int count = 0;
    int i;
    for(i=n-1; i > 0; i--)
    {
        if(s[i] == 'A')
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if(count == 7)
        {
            break;
        }
    }

    cout << (i+7-x) << "\n";
}