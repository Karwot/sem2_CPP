#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

float sumaCen(string fileName) {
    ifstream plik;
    plik.open(fileName);
    float tmp = 0, suma = 0;
    string nazwa = "";
    for(int i=0;i<3;i++) {
        plik >> nazwa >> tmp;
        suma+= tmp;
    }
    plik.close();
    return suma;
}

int main () {
    cout << "suma cen zakupow w koszyku: " << sumaCen("koszyk.txt");
    return 0;
}