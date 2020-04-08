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