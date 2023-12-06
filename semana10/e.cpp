#include <iostream>
#include <cmath>

using namespace std;

bool isTriangularOdd(int N) {
    int root = sqrt(2 * N);
    return (root * (root + 1) / 2 == N && root % 2 == 1);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (isTriangularOdd(N)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}