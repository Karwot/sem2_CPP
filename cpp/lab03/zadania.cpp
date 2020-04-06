#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

// 1 (a)
void printArr(int* pocz, int* koniec) {
    for(int* i =  pocz; i<koniec; i++) {
        cout << *i << " ";
    }
    cout << "\n";
}
// 1 (b)
int maxInArr(int* b, int* e) {
    int max = *b;
    for(int *i=b; i<e; i++) {
        if(*i>max)
            max = *i;
    }
    return max;
}
// 1(c)
void findInArr(int x, int* pocz, int* koniec) {
    int *i = pocz;
    while(i<koniec && *i!=x) {
        i++;
    }
    if(*i==x)
        cout << "element " << x << " znajduje sie w tablicy na indeksie " << *i;
    else
        cout << "nie ma tego elementu w tablicy";
}

unsigned long long Newton( unsigned int n, unsigned int k)    
{
    double Wynik = 1;       
    
    for( unsigned int i = 1; i <= k; i++)  {
    Wynik = Wynik * ( n - i + 1 ) / i;      
    }
    
    return (unsigned long long) Wynik;      
}

int main() {

    srand(time(NULL));

    int arr[10];

    //wypelnianie tablicy losowymi zmiennymi przy pomocy wskaznikow
    for(int i = 0; i<10; i++) {
        *(arr+i) = rand() % 10 + 1;
    }

    printArr(arr, arr+10);
    cout << "najwieksza: " << maxInArr(arr, arr+10) << "\n";
    findInArr(5, arr, arr+10);


    //zadanie 3

    /*
    int N = 0;
    cout << "\nPodaj N \n";
    cin >> N;

    int t[N][N];
    cout << "\n";
    for(int n=0; n<N; n++) {
        for(int k=0; k<N; k++) {
            t[n][k] = Newton(n, k);
            cout << t[n][k] << " ";
        } cout << "\n";
    }
    */

   //ZADANIE 2
   // (a)

    long int n = 0;
    cout << "\nPodaj n\n";
    cin >> n;

    int rozmiar = 0;
    int TMPn = n;
   while (TMPn>0) {
       TMPn=TMPn/10;
       rozmiar++;
   }
   cout << "rozmiar " << rozmiar << "\n";

    int cyfry[rozmiar];

    int i = rozmiar-1;
   while(n>0) {
       cyfry[i] = n%10;
       n/=10;
       //cout << cyfry[i] << " ";
       i--;
   }
   cout << endl;
   for(int ii=0; ii<rozmiar; ii++)
    cout << cyfry[ii] << " ";
    cout << endl;
}



