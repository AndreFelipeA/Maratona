#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;

    cin >> N;

    list<ll> l;
    list<ll>::iterator itr = l.begin(); 
    for(int k = 0; k < N; k++)
    {
        char c;

        cin >> c;

        if(c == 'm')
        {
            int D;
            cin >> D;
            if(D < 0)
            {
                for(int z = D; z < 0; z++)
                {
                    --itr;
                }
            }
            else
            {
                for(int z = 0; z < D; z++)
                {
                    ++itr;
                }
            }   
        }

        if(c == 'i')
        {
            int Q;
            ll T;
            cin >> Q >> T;

            for(int z = 0; z < Q; z++)
            {
                l.insert(itr,T);
                --itr;
            }
        }

        if(c == 'd')
        {
            itr = l.erase(itr);
        }

        if(c == 'q')
        {
            cout << *itr << "\n";
        }
        
    }

}