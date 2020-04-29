#include <iostream>
using namespace std;

class Cena {
    private:
    
    Cena() {
        netto = 0;
        brutto = 0;
        vat = 0;    
    }

    public:
    float netto;
    float brutto;
    float vat;
    float getNetto() { return netto; }
    float getBrutto() { return brutto ; }
    float getVat() { return vat; }

    static Cena fromNetto(float cenaNetto, float vat_) {
        Cena r;
        r.netto = cenaNetto;
        r.vat = vat_;
        r.brutto = 1.0*cenaNetto*(1+vat_/100);
        return r;
    }

    static Cena fromBrutto(float cenaBrutto, float vat_) {
        Cena r;
        r.vat = vat_;
        r.brutto = cenaBrutto;
        r.netto = (1.0*cenaBrutto)/(1+vat_/100);
        return r;
    }

    const string toString() {
        return "brutto: "+to_string(brutto)+"netto: "+to_string(netto)+" vat: "+to_string(vat);
    }
    const string toXML() {
        return "<brutto>"+to_string(brutto)+"</brutto>\n<netto>"+to_string(netto)+"</netto>\n<vat>"+to_string(vat)+"</vat>";

    }

};

int main() {



    Cena c1 = Cena::fromBrutto(100,23);
    cout << "brutto:" << c1.getBrutto() << " netto: " << c1.getNetto() << " vat: " << c1.getVat() << endl;
    Cena c2 = Cena::fromNetto(100,23);
    cout << "brutto:" << c2.getBrutto() << " netto: " << c2.getNetto() << " vat: " << c2.getVat() << endl;

    cout << c2.toString() << endl;
    cout << c2.toXML();
    //c1.fromNetto(100,23);
    return 0;
}