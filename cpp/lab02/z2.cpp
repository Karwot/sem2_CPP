#include <iostream>
#include <cstdio>
using namespace std;

float horner(int* wspolczynniki, int stopien, int x) {
        if(stopien==0)
                return wspolczynniki[0];
        return x*horner(wspolczynniki, stopien-1, x)+wspolczynniki[stopien];
}

int main() {
        int x, stopien;
        cout << "Podaj stopien wielomianu: \n";
                cin >> stopien;
        cout << "Podaj argument x dla ktorego wyliczamy wartosc wielomianu: \n";
                cin >> x;
        int wspolczynniki[stopien+1];
                for(int i=stopien; i>=0; i--) {
                        cout << "podaj wspolczynnik przy potedze " << i << "\n";
                        cin >> wspolczynniki[i];
                }
        cout << "wynik: " << horner(wspolczynniki, stopien, x) << "\n";
return 0;
}