#include <iostream>
#include <string>
using namespace std;

class Masa {
   private:
    int g;
    int kg;
    int t;
    public:
    Masa() : g(0), kg(0), t(0) {}

    Masa(float _kg)  {
        if(_kg<1) {
            g = _kg*1000;
            kg = 0;
            t = 0;
        }
        else if(kg>1000) {
            t = _kg/1000;
            kg = _kg-1000*t;
            g = _kg*100-t*100000-kg*100;
        } else {
            t = 0;
            kg = _kg;
            g = 0;
        }
    }

    float toKg() {
        return 1.0*g/1000+kg+1000*t;
    }

    string toString() {
        if(t>0) 
            return to_string(t)+"."+to_string(kg)+to_string(g)+"T"; 
        if(kg>0)
            if(g>0)
                return to_string(kg)+"."+to_string(g)+"kg";
            else
                return to_string(kg)+"kg";
                
    return to_string(g)+"g";
    }

    friend ostream & operator << (ostream &out, Masa &m);
    friend bool operator<( Masa& m1,  Masa& m2);
    Masa operator+( Masa& m1 ) {
       float kilo = this->toKg() + m1.toKg();
       Masa result(kilo);
       return result;
    };
};

bool operator<( Masa& m1,  Masa& m2) {
    return (m1.toKg()<m2.toKg());
};

ostream & operator << (ostream &out, Masa &m) {
    out << m.toString();
    return out;
};

int main() {

    Masa p1(1250.5);
    Masa p2(125.0);
    Masa p3(0.6);
    cout << "Masa nr1: " << p1.toString() << " -> konwersja do typu string wg wzoru\n";
    cout << "Masa nr2: " << p2.toKg() << " -> (metoda zwracajaca kilogramy,  typ rzeczywisty), " << p2.toString() << "(metoda zwracajaca napis wg wzoru)\n";
    cout << "Masa nr3: " << p3.toString() << " -> konwersja do typu string wg wzoru(wypisanie wartosci w gramach) \n ";
    Masa p4;
    p4 = p1+p2;
    cout << "dodawanie: " << p4;
    return 0;
}