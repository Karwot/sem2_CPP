#include <cstdio>
#include <iostream>
using namespace std;

void rev(int* arr, int n) {
int rindx = n-1;
int tmp[n];
for(int i=0; i<n; i++) {
tmp[i] = arr[rindx];
rindx--;
}
for(int i=0; i<n; i++) {
arr[i] = tmp[i];
}
}

void toRight(int *arr, int n) {
        int tmp[n];
        for(int i=0; i<n; i++)
                tmp[i] = arr[i];
        arr[0] = tmp[n-1];
        arr[n-1] = tmp[n-2];
        for(int j=1; j<n-1; j++)
                arr[j] = tmp[j-1];
}

void sortArr(int* arr, int n) {
        for(int i=0;i<n-1;i++) {
                for(int j=i+1;j<n;j++) {
                        if(arr[i]>arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
}

void printArr(int* arr, int n) {
        for(int i=0; i<n; i++)
                cout << arr[i] << " ";
        cout << "\n";
}

int main()
{

        int t1[10] = { 4, 10, 15, 13, 44, 85, 6, 7, 8, 9 };

        printArr(t1,10);
        rev(t1, 10);
        printArr(t1, 10);
        toRight(t1, 10);
        printArr(t1,10);
        sortArr(t1, 10);
        printArr(t1, 10);

return 0;
}

*/

//ZADANIE2 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
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
*/

//ZADANIE 4 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <random>
using namespace std;

int liczbaLosowa(int a, int b) {
        return rand() % b + a;
}

double liczbaLosowa(double a, double b) {
        double r = ((double)rand()/(double)(RAND_MAX/(b-a)));
        return a+r;
}


int main() {

srand (time(NULL));

cout << liczbaLosowa(1,7) << "\n";
cout << liczbaLosowa(5.1,5.3) << "\n";


return 0;
}
*/

//ZADANIE5 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long int silnia(int n) {
        if(n<2)
                return 1;

        return n*silnia(n-1);
}

int main() {


for(int i=0; i<=5; i++) {
                cout << "silnia z " << i << "= " << silnia(i) << "\n";
}

return 0;
}

*/

///// ZADANIE 7 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
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

*/
//ZADANIE8 @@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
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

*/