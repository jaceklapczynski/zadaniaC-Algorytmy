#include <iostream>

using namespace std;

const long long MOD = 1000000007;

long long mod_exp(long long podstawa, long long wykladnik) {
    long long wynik = 1;
    while (wykladnik > 0) {
        if (wykladnik % 2 == 1) {
            wynik = (wynik * podstawa) % MOD;
        }
        podstawa = (podstawa * podstawa) % MOD;
        wykladnik /= 2;
    }
    return wynik;
}

int main() {
    int t;
    cin >> t;
    long long n;
    while (t--) {
        cin >> n;

        if (n == 1){
            cout << "0\n";
        }
        else {
            long long nn = mod_exp(n, n);
            long long result = (nn - n + MOD) % MOD;
            cout << result << endl;
        }
    }
    return 0;
}
