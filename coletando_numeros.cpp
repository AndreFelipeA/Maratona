#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<int,int>> v;
    for(int i =0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(make_pair(x,i));
    }

    sort(v.begin(),v.end());
    int count = 1;
    for(int i =0; i<n-1; i++)
    {
        if(v[i].second > v[i+1].second)
        {
            count++;
        }
    }

    cout << count << "\n";
}



