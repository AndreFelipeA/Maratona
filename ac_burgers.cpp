#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {
        int P, H, F, D,C;
        cin >> P >> H >> F >> D >> C;
        int total = 0;
        for(int i = P; i >1; i-=2)
        {
            if(H == 0 && F == 0)
            {
                break;
            }
            if(C >= D && F > 0)
            {
                F -= 1;
                total += C;
                continue;
            }
            if(D > C && H > 0)
            {
                H -= 1;
                total += D;
                continue;
            }
            if(F == 0 && H > 0)
            {
                H -= 1;
                total += D;
                continue;

            }
            if(H == 0 && F > 0)
            {
                F -= 1;
                total += C;
                continue;
            }


        }

        cout << total << "\n";
    }
}