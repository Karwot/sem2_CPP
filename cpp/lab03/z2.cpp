  #include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {

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
    return 0;
}