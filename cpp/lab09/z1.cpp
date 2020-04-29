#include <iostream>
#include <string>
using namespace std;

class Punkt{
public:
    Punkt() : x(0), y(0), z(0) {}
    Punkt(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {} 
    double x,y,z;

    friend ostream& operator<<(ostream& out, const Punkt& p);
};

Punkt operator+(const Punkt& a, const Punkt& b) {
     return Punkt(a.x+b.x,a.y+b.y,a.z+b.z);
}

Punkt operator-(const Punkt& a, const Punkt& b) {
     return Punkt(a.x-b.x,a.y-b.y,a.z-b.z);
}

ostream& operator<<(ostream& out, const Punkt& p) {
    out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
}

int main() {
    
    Punkt p1(1, 2, 3);
    Punkt p2(4, 5, 6);
    cout << "Wypisanie punktow za pomoca przeciazonego operatora << " << endl << "Punkt p1: " << p1 << endl;
    p1 = p1+p2;
    cout << "Punkt p1 po dodaniu p2 za pomoca przeciazonego operatora + " << p1;

return 0;
}