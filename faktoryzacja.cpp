#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void rozklad(int a){
    if(a == 1) {
        cout << endl;
        return;
    }
    int b = 2;
    while(a>1 && b<=sqrt(a))
    {
        while(a % b == 0)
        {
            cout << b << " ";
            a = a / b;
        }
        b++;
    }
    if(a > 1) cout << a;
    cout << endl;
}

int main(){
ios_base::sync_with_stdio(false); cin.tie (nullptr);
int t, k;
cin >> t;
vector<int> tablica(t);
for(int i = 0; i < t; i++){
    cin >> tablica[i];
}
for(int j = 0; j < t; j++){
    rozklad(tablica[j]);
}

}
