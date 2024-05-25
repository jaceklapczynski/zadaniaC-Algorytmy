#include <iostream>
#include <vector>
using namespace std;

long long zliczanie(int n, const vector<short>& directions){
    int wschod = 0;
    long long wynik = 0;

    for(int i = 0; i < n; i++){
        if(directions[i] == 0){
            wschod++;
        }
        else{
            wynik += wschod;
        }
    }
    return wynik;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie (nullptr);
    int n;
    cin >> n;
    vector<short> directions(n);
    for(int j = 0; j < n; ++j) {
        cin >> directions[j];
    }

    cout << zliczanie(n, directions);
}
