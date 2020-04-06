#include <iostream>
#include <cstdio>
#include <cmath>
#include <time.h>
using namespace std;

int liczbaLosowa(int a, int b) {
        return rand() % b + a;
}

int liczbaLosowa(int* a, int* b) {
        return rand() % *b + *a;
}

void liczbaLosowa(int a, int b, int& losowa) {
        losowa = rand() % b + a;
}

int main() {

    srand(time(NULL));

        int losowa = 1;
        int a = 1;
        int b = 10;

        cout << "wartosc: ";
            cout << liczbaLosowa(a,b);
        cout << "\nwskaznik: ";
            cout << liczbaLosowa(&a, &b);
        cout << "\nreferencja: ";
        liczbaLosowa(a, b, losowa);
        cout << losowa;
        
return 0;
}