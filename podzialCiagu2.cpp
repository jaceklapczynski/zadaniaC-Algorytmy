#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool mozliwe(vector<int>& ciag, int k, int limit) {
    int count = 1;
    int suma = 0;
    for (int liczba : ciag) {
        suma += liczba;
        if (suma > limit) {
            suma = liczba;
            count++;
        }
    }
    return count <= k;
}

int najmniejszaSuma(vector<int>& ciag, int k) {
    int dolna = *max_element(ciag.begin(), ciag.end());
    int gorna = accumulate(ciag.begin(), ciag.end(), 0);
    while (dolna < gorna) {
        int srodek = dolna + (gorna - dolna) / 2;
        if (mozliwe(ciag, k, srodek)) {
            gorna = srodek;
        } else {
            dolna = srodek + 1;
        }
    }
    return dolna;
}

int main() {
    int n;
    int k;
    int wynik;
    cin >> n >> k;
    vector<int> ciag(n);
    for (int i = 0; i < n; i++) {
        cin >> ciag[i];
    }
    wynik = najmniejszaSuma(ciag, k);
    cout << wynik << endl;
    return 0;
}
