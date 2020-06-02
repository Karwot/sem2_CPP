#include <iostream>
#include <string>
using namespace std;
template <class T>
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
    double arrDouble[] = { 8.2, 7.3, 1.5, 6.3 };
    char arrChar[] = { 'q','w','e','r','t','y','u','i','o','p' };
    string arrString[] = { "alfa", "beta", "gamma", "delta", "epsilon"};

    wypisz<int>(arrInt, arrInt+4); cout << "\n";
    wypisz<double>(arrDouble, arrDouble+4, '_'); cout << "\n";
    wypisz<char>(arrChar, arrChar+10, ','); cout << "\n";
    wypisz<string>(arrString,arrString+5, '/');
    
    return 0;
}

// Odpowiedź na pytanie: W funkcji można używać tych typów danych, które da się wypisać na strumien wyjścia za pomocą operatora <<.