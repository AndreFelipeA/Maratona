#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;

    cin >> T;

    while(T--)
    {
        ll L;
        int N;

        cin >> L >> N;


        ll menor = 0, maior = 0;
        for(int i=0; i < N; i++)
        {
            ll F;
            cin >> F;

            if((L-F) <= F)
            {
                if(menor < (L-F))
                {
                    menor = (L-F);
                }
            }
            else
            {
                if(menor < (F))
                {
                    menor = (F);
                }
            }

            if((L-F) <= (F) && maior < (F))
            {
                maior = F;
            }
            else if((F) <= (L-F) && maior < (L-F))
            {
                maior = (L-F);
            }
        }
        cout << menor << " " << maior << "\n";
    }
}