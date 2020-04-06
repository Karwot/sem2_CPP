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
    int *i = pocz, index = 0;
    while(i<koniec && *i!=x) {
        i++;
        index++;
    }
    if(*i==x)
        cout << "element " << x << " znajduje sie w tablicy na indeksie " << index;
    else
        cout << "nie ma tego elementu w tablicy";
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

    return 0;
}