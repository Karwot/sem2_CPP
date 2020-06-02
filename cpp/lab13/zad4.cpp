#include <iostream>
#include <string>
using namespace std;
template<typename T> 
auto suma(const T* poczatek, const T* zaKoncem) {
    int iloscElementow = zaKoncem-poczatek;
    T result;
    for(int i=0; i<iloscElementow; i++) 
        result = result + (*(poczatek+i));
    return result;
}
template<typename T>
void wypisz(const T* poczatek, const T* zaKoncem, char separator=' '){
    int iloscElementow = zaKoncem-poczatek;
    for(int i=0; i<iloscElementow; i++) {
        cout << *(poczatek+i);
        if(i!=iloscElementow-1)
            cout << separator;
    }
};


int main() {

    int arrInt[] = { 5, 4, 2, 3 };
    double arrDouble[] = { 8.2, 7.3, 1.5, 6.3, 1.3 };
    string arrString[] = { "alfa", "beta", "gamma", "delta" };

    wypisz(arrInt, arrInt+4, '+'); 
    cout << " = " << suma(arrInt, arrInt+4) << "\n";
    wypisz(arrDouble, arrDouble+5, '+'); cout << " = " << suma(arrDouble, arrDouble+5) << "\n";
    wypisz(arrString, arrString+4); cout << " = " << suma(arrString, arrString+4);
    return 0;
}

// Odpowiedz na pytanie: W funkcji powinno się używać typów danych, które można sumować za pomocą operatora '+';