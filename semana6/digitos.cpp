#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Função que calcula a raiz digital de um número
int digital_root(ll n) {
    return (n - 1) % 9 + 1;
}

// Função que verifica se o dígito verificador de uma operação é válido
bool check_digit(int op, const vector<int>& numbers, int a1, int b1, int a2, int b2, int d) {
    ll x = 0, y = 0, z = 0;
    if (op == 1) {
        x = accumulate(numbers.begin() + a1 - 1, numbers.begin() + b1, 0LL);
        y = accumulate(numbers.begin() + a2 - 1, numbers.begin() + b2, 0LL);
        z = digital_root(x + y);
    } else if (op == 2) {
        x = accumulate(numbers.begin() + a1 - 1, numbers.begin() + b1, 1LL, multiplies<ll>());
        y = accumulate(numbers.begin() + a2 - 1, numbers.begin() + b2, 1LL, multiplies<ll>());
        z = digital_root(x * y);
    }
    return z == d;
}

int main() {
    // Leitura dos dados de entrada
    int n, q;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        numbers[i] = c - '0';
    }
    cin >> q;
    // Processamento das operações
    while (q--) {
        int op;
        cin >> op;
        if (op == 1 || op == 2) {
            int a1, b1, a2, b2, d;
            cin >> a1 >> b1 >> a2 >> b2 >> d;
            if (check_digit(op, numbers, a1, b1, a2, b2, d)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (op == 3) {
            int p, d;
            cin >> p >> d;
            numbers[p - 1] = d;
        }
    }
    return 0;
}