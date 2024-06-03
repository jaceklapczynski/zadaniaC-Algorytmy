#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;
    cin >> z;

    vector<pair<unsigned int, unsigned int>> data(z);
    unsigned int max_s = 0;
    unsigned int max_p = 0;

    for (unsigned int i = 0; i < z; ++i) {
        unsigned int s, p;
        cin >> s >> p;
        data[i] = {s, p};
        if (s > max_s) max_s = s;
        if (p > max_p) max_p = p;
    }

    unsigned int max_mod = 1 << max_p;
    vector<unsigned long long> f(max_s + 1);
    f[0] = 1;
    f[1] = 1;

    for (unsigned int k = 2; k <= max_s; ++k) {
        f[k] = (f[k - 1] + f[k - 2]) % max_mod;
    }

    for (const auto& [s, p] : data) {
        unsigned int current_mod = 1 << p;
        cout << f[s] % current_mod << endl;
    }

    return 0;
}
