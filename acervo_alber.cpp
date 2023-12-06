#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool>chosen(13);
vector<int>estante(13);
vector<vector<int>> regras(14, vector<int>(14,0));
int tam;


bool obey_rules(int kth, int value)
{
    int rule = true;

    for(int i=0; i < kth; i++)
    {
        if(regras[value][estante[i]] == 1)
        {
            rule = false;
        }
    }

    
    if(rule == false)
    {

        return false;
    }
    else return true;
}

void gen(int kth) {
    if (kth == tam)
    {
        for (int i = 0; i < tam; i++)
        {
            cout << estante[i] << " "; 
        }   cout << '\n';
        return; 
    }

    for (int i = 1; i <= tam; i++) 
        if (!chosen[i] && obey_rules(kth, i))
        {
            chosen[i] = 1; 
            estante[kth] = i; gen(kth+1); 
            chosen[i] = 0;
        }
}


int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);

    int c;
    cin >> tam >> c;

    int r1, r2;
    for(int i = 0; i < c; i++){
        cin >> r1 >> r2;
        regras[r1][r2] = 1;
    }


    for(int i = 0; i < tam; i++){
        cin >> estante[i];
    }

    gen(0);

}