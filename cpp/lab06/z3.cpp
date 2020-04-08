#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Trojkat {
    int a;
    int b;
    int c;
    float pole;
    Trojkat* next;
};

void addElement(Trojkat** start, int a, int b, int c) {
    Trojkat* newElem = new Trojkat;
    
    newElem->a = a;
    newElem->b = b;
    newElem->c = c;

    newElem->next = (*start);
    (*start) = newElem;
}

void listElements(Trojkat* start) {
    while(start) {
        cout << "Pole trojkata " <<start->a <<"," << start->b << "," << start->c << " = " <<  start->pole << endl;
        start = start->next;
    }
}

void pola(Trojkat* start) {
    int a, b, c;
    float tmp, p;
    while(start) {
        int a, b, c;
        a = start->a;
        b = start->b;
        c = start->c;
        p = (1.0*(a+b+c))/2;
        start->pole = sqrt(p*(p-a)*(p-b)*(p-c));
        start = start->next;
    }
}

int main() {
    Trojkat* start = NULL;
    addElement(&start, 5, 7, 11);
    addElement(&start, 7, 13, 17);
    addElement(&start, 8, 15, 11);
    addElement(&start, 13, 8, 11);
    pola(start);
    listElements(start);
    return 0;
}