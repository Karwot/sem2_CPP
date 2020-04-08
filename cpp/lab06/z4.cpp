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