#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

unsigned long long Newton( unsigned int n, unsigned int k)    
{
    double Wynik = 1;       
    
    for( unsigned int i = 1; i <= k; i++)  {
    Wynik = Wynik * ( n - i + 1 ) / i;      
    }
    
    return (unsigned long long) Wynik;      
}

int main() {

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

    return 0; 
}