#include <iostream>
#include <string>
using namespace std;

class Punkt{
private:
    string nazwa;
public:
    Punkt() : x(0), y(0), z(0) {
        nazwa = "domyslna";
    }
    Punkt(const Punkt& a) : x(a.x), y(a.y), z(a.z), nazwa(a.nazwa) { }
    Punkt(double _x, double _y, double _z, string _nazwa) : x(_x), y(_y), z(_z), nazwa(_nazwa) {}
    double x,y,z;

    friend ostream& operator<<(ostream& out, const Punkt& p);
    
   Punkt& operator= (const Punkt &p)
    {
    // do the copy
    x = p.x;
    y = p.y;
    z = p.z;
    nazwa = p.nazwa;
    // return the existing object so we can chain this operator
    return *this;
    }

};


Punkt operator+(const Punkt& a, const Punkt& b) {
     return Punkt(a.x+b.x,a.y+b.y,a.z+b.z, "suma");
}

Punkt operator-(const Punkt& a, const Punkt& b) {
     return Punkt(a.x-b.x,a.y-b.y,a.z-b.z, "roznica");
}

ostream& operator<<(ostream& out, const Punkt& p) {
    out << p.nazwa << ": (" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
}


int main() {

    Punkt p1(1, 2, 3, "Punkt1");
    Punkt p2(4, 5, 6, "Punkt2");
    Punkt p3, p4;

    cout << "Wypisanie punktow za pomoca przeciazonego operatora << " << p1 << endl;
    p3 = p1+p2;
    p4 = p1-p2;
    cout << "Przeciazone opratory dodawania i odejmowania:" << endl << p3 << endl << p4 << endl;

    Punkt p5(p1), p6;
    cout << "P5 ktory jest kopia punktu1(kostruktor kopiujacy): " << p5 << endl;
    p6 = p2;
    cout << "P6 ktory jest kopia p2(przeciazony operator przypisania '=' ): " << p6;

return 0;
}

//Odpowiedz na pytanie: Czy zdefiniowanie własnego konstruktora kopiującego i przeciążenie operatora '=' było konieczeczne?
//Odp.: Nie było konieczne. Operator '=' działa w ten sam sposób bez potrzeby przeciążania go.