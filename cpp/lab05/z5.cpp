#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int linesInFile(string fileName) {
    ifstream inputFile(fileName);
    char ch;
    int lines = 1;
    while (inputFile) {
        inputFile.get(ch);
        if(ch=='\n')
            lines++;
    }
    inputFile.close();
    return lines;
}

float sumaCen(string fileName) {
    ifstream plik;
    plik.open(fileName);
    float tmp = 0, suma = 0;
    string nazwa;
    char ch;
    for(int i=0; i<linesInFile(fileName); i++) {
        nazwa = "";
        while(nazwa[nazwa.length()-1]!=':')
            plik >> nazwa;
        plik >> tmp;
        suma+=tmp;
    }

    plik.close();
    return suma;
}

void addProduct(string fileName, string name, float price) {
    ofstream plik;
    plik.open(fileName, ios::app);
    plik << endl << name << ": " << price;
    plik.close();
}

/*void remove(string fileName, string name, int line) {
    for(int i=0; i<line: i++) {

    }
}*/

int main () {
    string fileName = "cart.txt";
    cout << "suma cen zakupow w koszyku: " << sumaCen(fileName);
    string productName = "coca cola";
    float productPrice = 3.50;
    cout << endl <<  "dodaje produkt " << productName << " o wartosci " << productPrice;
    addProduct(fileName, productName, productPrice); 

    return 0;
}