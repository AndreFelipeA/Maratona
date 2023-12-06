#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() 
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    // implemente sua lógica

    int N;
    cin >> N;
    
    vector<ll> v;
    for (int i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    
    int n = v.size();
    stack <ll> st;

    ll ls[n], rs[n];
    
    for (int i = 0; i < n; i++)
    {
    while (!st.empty() && v[st.top()] >= v[i])
    {
        st.pop();
    }
    if (st.empty())
    {
        ls[i] = 0;

    }
    else
        ls[i] = st.top() + 1;
    st.push(i);
    }


    while (!st.empty())
    st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] >= v[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            rs[i] = n - 1;
        }
        else
            rs[i] = st.top() - 1;

        st.push(i);
    }

    ll maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, v[i] * (rs[i] - ls[i] + 1));
    }

    cout << maxArea << "\n";



}