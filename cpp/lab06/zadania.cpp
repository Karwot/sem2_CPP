//#################ZADANIE1 ############################
/*

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

*/
//#################ZADANIE2 ############################
/*

#include <iostream>
#include <cstdio>
using namespace std;

struct Element
{
  Element* next;
  int val;
};


void addElement(Element**  start, int value) {
    Element* newElem = new Element;
    newElem->next = (*start);
    newElem->val = value;
    (*start) = newElem;
}

void listElements(Element* start) {
    while(start) {
        cout << start->val << " ";
        start = start->next;
    }
    cout << endl;
}

void toAbs(Element* start) {
    while(start) {
        start->val = abs(start->val);
        start = start->next;
    }
}

int main() {

    Element* start = NULL;
    addElement(&start, 5);
    addElement(&start, -4);
    addElement(&start, 12);
    addElement(&start, -5);
    addElement(&start, 5);
    addElement(&start, 23);
    addElement(&start, -17);

    cout << "before: ";
    listElements(start);
    toAbs(start);
    cout << "after: ";
    listElements(start);

    return 0;
}

*/
//#################ZADANIE3 ############################
/*

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

*/
//#################ZADANIE4 ############################
/*

#include <iostream>
#include <cstdio>
using namespace std;

struct Element {
    string value;
    Element* next;
};

void addElem(Element** start, string value) {
    Element* newElem = new Element;
    newElem->value = value;
    newElem->next = (*start);
    (*start) = newElem;
}

void reversi(Element** start) {
    while(*start) {
        Element* temp = *start;
        *start = (*start)->next;
        if(temp->value!="end")
            cout << temp->value << " ";
        delete temp;
    }
    cout << endl;
}

int main() {

    Element* start = NULL;
    string s;
    cout << "Type words or type \"end\" to view the result" << endl;
    while(s!="end") {
        getline(cin, s);
        addElem(&start, s);        
    }
    reversi(&start);

    return 0;
}

*/