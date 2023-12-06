#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
     cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    string s;
    int guardas = 0;
    int coloca = 0;
    int caso = 1;
    while(t--)
    {
        getline(cin, s);
        cout << s;
        int n = s.size();
       
        for(int i=0; i< n; i++)
        {
            if(s[i] == '_')
            {
                coloca++;
            }

            if(coloca == 3)
            {
                guardas++;
                coloca = 0;
            }

            if(coloca == 2 & s[i-1] == '#')
            {
                guardas++;
                coloca = 0;
            }

            if(coloca)

        }

        cout << "\n";
        cout << "Caso " << caso << ":" << guardas << "\n";
        guardas = 0;
        coloca = 0;
        caso++;
    }
}