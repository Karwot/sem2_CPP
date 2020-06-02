#include<iostream>
#include<string>
template <class T>
const T* minimum(const T* poczatek, const T* zaKoncem){
    /*const T* min = poczatek;
    int iloscElementow = zaKoncem-poczatek;
    for(int i=0; i<iloscElementow; i++) {
        if(*min>*(poczatek+i))
            min = (poczatek+i);
    }
    return min; */
    const T* min = poczatek;
    for(const T* wsk = poczatek; wsk<zaKoncem; wsk++) {
        if(*min>*wsk)
            min = wsk;
    }
    return min;
};

template<typename T>
void wypisz(const T* poczatek, const T* zaKoncem, char separator=' '){
    int iloscElementow = zaKoncem-poczatek;
    for(int i=0; i<iloscElementow; i++) {
        std::cout << *(poczatek+i);
        if(i!=iloscElementow-1)
            std::cout << separator;
    }
};

int main() {

    int arrInt[] = { 5, 4, 2, 3, 1 };
    double arrDouble[] = { 8.2, 7.3, 1.5, 6.3, 1.3, 0.3, 7.2, 0.2 };
    const char* napis[] = { "delta", "gamma", "beta", "alfa" } ;
    std::string n[4] =  { "delta", "gamma", "beta", "alfa" } ;
    std::cout << "tablica int: "; wypisz(arrInt, arrInt+5);
        std::cout << " |Minimalna wartosc: " << *(minimum(arrInt, arrInt+5)) << "\n";
    std::cout << "tablica double: "; wypisz(arrDouble, arrDouble+7);
        std::cout << " |Minimalna wartosc: " << *(minimum(arrDouble, arrDouble+7)) << "\n";
    std::cout << "tablica char: "; wypisz(napis, napis+4, ',');
        std::cout << " |Minimalna wartosc: " << *minimum(napis, napis+4) << "\n";
    std::cout << "str: "; wypisz(n, n+4, ',');
        std::cout << "|minimalna wartosc: " << *minimum(n, n+4);
    

    return 0;
}

// Odpowiedź na pytanie do zadania 5: Dla tablicy napisów char* [] nie jest znajdowane minimum. Nie można porównywać wartości tego typu 
//  operatorami '<', '>'. Wypisywana jest pierwsza wartość z listy(domyślnie przypisana do zmiennej zwracanej na początku algorytmu)
// Aby odnajdować napis który jest pierwszy alfabetycznie pomocna wydaje się biblioteka string.