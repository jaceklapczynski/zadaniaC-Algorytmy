#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie (nullptr);
    int z;
    cin >> z;

    vector<pair<int, int>> data(z);
    int max_s = 0;
    int max_p = 0;

    for (int i = 0; i < z; ++i) {
        int s, p;
        cin >> s >> p;
        data[i] = {s, p};
        if (s > max_s) max_s = s;
        if (p > max_p) max_p = p;
    }

    int mod = pow(2, max_p);
    vector<long long> f(max_s + 1);
    f[0] = 1;
    f[1] = 1;

    for (int k = 2; k <= max_s; ++k) {
        f[k] = (f[k - 1] + f[k - 2]) % mod;
    }

    for (const auto& [s, p] : data) {
        int current_mod = pow(2, p);
        cout << f[s] % current_mod << endl;
    }

    return 0;
}
