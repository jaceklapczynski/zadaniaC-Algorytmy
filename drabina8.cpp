#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MOD = 1073741824; // 2^30

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int z;
    scanf("%d", &z);

    vector<pair<unsigned int, unsigned int>> data(z);
    unsigned int max_s = 0;

    for (int i = 0; i < z; ++i) {
        unsigned int s, p;
        scanf("%u %u", &s, &p);
        data[i] = {s, p};
        if (s > max_s) max_s = s;
    }

    // Precompute Fibonacci sequence up to max_s modulo MOD
    vector<unsigned long long> f(max_s + 1);
    f[0] = 1;
    if (max_s > 0) f[1] = 1;

    for (unsigned int k = 2; k <= max_s; ++k) {
        f[k] = f[k - 1] + f[k - 2];
        if (f[k] >= MOD) f[k] -= MOD;
    }

    // Output results for each query
    for (const auto& [s, p] : data) {
        printf("%llu\n", f[s] % (1U << p));
    }

    return 0;
}
