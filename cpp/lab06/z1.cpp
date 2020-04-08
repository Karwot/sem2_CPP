#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct Magazyn {
    string nazwa_towaru;
    float cena;
};

int lastIndex = 0;
Magazyn* towar[1000];

Magazyn* newItem(string name, float price) {
    Magazyn* item = new Magazyn;
    item->nazwa_towaru = name;
    item->cena = price;
    return item;
} 

void addItem(string name, float price) {
    if(lastIndex==999){
        cout << "Wyczerpano miejsce w magazynie" << endl;
        return;
    }
    Magazyn* n = newItem(name, price);
    towar[lastIndex] = n;
    lastIndex++;
}

int count(string name) {
    int result = 0;
    for(int i=0; i<lastIndex; i++)
        if(towar[i]->nazwa_towaru==name)
            result++;
    return result;
}

int main() {
    
    addItem("mleko", 3.50);
    addItem("cola", 2.50);
    cout << towar[0]->nazwa_towaru << " " << towar[0]->cena;
    cout << endl << count("mleko");

    return 0;
}