#include <iostream>
using namespace std;

class Punkt{
public:
    Punkt() : x(0), y(0), z(0) {}
    Punkt(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {} 
    double x,y,z;

    friend ostream& operator<<(ostream& out, const Punkt& p);
};

class Wektor {
    public:
    Punkt poczatek;
    Punkt koniec;

    Wektor(double x1, double y1, double z1, double x2, double y2, double z2) : poczatek(x1, y1, z1), koniec(x2, y2, z2) {}
    Wektor(Punkt pocz, Punkt kon) : poczatek(pocz), koniec(kon) {}
    friend ostream& operator<<(ostream& out, const Wektor& v);
};

    ostream& operator<<(ostream& out, const Wektor& v) {
        out << "Poczatek: (" << v.poczatek.x << ", " << v.poczatek.y << ", " << v.poczatek.z << ") Koniec: (" << v.koniec.x << ", " << v.koniec.y << ", " << v.koniec.z << ")";
        return out;
    }

Wektor operator+(const Wektor& a, const Wektor& b) {
    return Wektor(a.poczatek.x+b.poczatek.x, a.poczatek.y+b.poczatek.y, a.poczatek.z+b.poczatek.z, a.koniec.x+b.koniec.x, a.koniec.y+b.koniec.y,a.koniec.z+b.koniec.z);
}
Wektor operator-(const Wektor& a, const Wektor& b) {
        return Wektor(a.poczatek.x-b.poczatek.x, a.poczatek.y-b.poczatek.y, a.poczatek.z-b.poczatek.z, a.koniec.x-b.koniec.x, a.koniec.y-b.koniec.y,a.koniec.z-b.koniec.z);
}
Wektor operator*(const Wektor& v, double _x) {
    return Wektor(v.poczatek.x*_x, v.poczatek.y*_x, v.poczatek.z*_x, v.koniec.x*_x, v.koniec.y*_x, v.koniec.z*_x);
}
Wektor operator*(const Wektor& v, const Wektor& v2) {
    return Wektor(v.poczatek.x*v2.poczatek.x, v.poczatek.y*v2.poczatek.y, v.poczatek.z*v2.poczatek.z,
     v.koniec.x*v2.koniec.x, v.koniec.y*v2.koniec.y, v.koniec.z*v2.koniec.z);
}
int main() {

    Punkt p1(1,2,3);
    Punkt p2(4,5,6);
    Wektor v1(p1, p2);
    Wektor v2(p2, p1);
    cout << "Wektor 1: " << v1 << endl;
    cout << "Wektor 2: " << v2 << endl;
    Wektor v3 = v1+v2;
    cout << "Suma v1+v2: " << v3 << endl;
    cout << "Roznica v1-v2: " << (v1-v2) << endl;
    Wektor v4 = v1*3;
    cout << "Wektor  v1 pomnozony przez liczbe 3: " <<  v4 << endl;
    cout << "Iloczyn v1*v2: " << (v1*v2) << endl;
return 0;
}