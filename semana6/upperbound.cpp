#include <bits/stdc++.h>
using namespace std;
int main() {
int n; while (cin >> n) {
vector<int> v (n); for (int& x : v) { cin >> x; }
auto it = upper_bound(v.begin(), v.end(), 2);
cout << it - v.begin() << "\n";
}
}