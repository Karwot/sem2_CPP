#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

short int fKwadratowa(float& a, float& b, float c) {
        float delta = b*b-4*(a*c);


        if( delta>0 ) {
            a = (-b+sqrt(delta))/(2*a);
            b = (-b-sqrt(delta))/(2*a);
            cout << "x1 = " << a << "\n";
            cout << "x2 = " << b << "\n";
            cout << "liczba rozwiazan tego rownania: ";
            return 2;
        }
        else if( delta == 0 ) {
                a = (-b+sqrt(delta))/(2*a);
                cout << "x1 = " << a;
                cout << "liczba rozwiazan tego rownania: ";
                return 1;
        }
        else {
            cout << "liczba rozwiazan tego rownania: ";
                return 0;
        } 
}

int main() {

        int x0 = 0;
        int x1 = 0;

        float a = 3;
        float b = 12;
        float c = 5;
        cout << "dla rownania kwadratowego o wspolczynnikach: \n";
        cout << "a:" << a << " b:" << b << " c:" << c << "\n";
        cout << "miejsca zerowe: \n " << fKwadratowa(a,b,c) << "\n";

return 0;
}