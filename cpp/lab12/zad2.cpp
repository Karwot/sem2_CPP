#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Pytanie {
private:
    string trescPytania;
    vector<string> trescOdpowiedzi;
protected:
        vector<int> udzieloneOdpowiedzi;
        vector<int> prawidloweOdpowiedzi;
        vector<int> ocenyOdp;
public:
    Pytanie()  {}
    ~Pytanie() {} 

    enum odpowiedzi {
        BAD_MARKED,
        BAD_UNMARKED,
        OK_MARKED,
        OK_UNMARKED
    };

    void getOdpowiedzi() {
        for(int i=0; i<trescOdpowiedzi.size(); i++) {
            cout << char(i+65) << ". " << trescOdpowiedzi[i] << "\n";
        }
    }
    void setTresc(string _tresc) {
        trescPytania = _tresc;
    }
    void addOdpowiedz(string _tresc, bool jestPrawidlowe) {
        trescOdpowiedzi.push_back(_tresc);
        if(jestPrawidlowe == true)
            prawidloweOdpowiedzi.push_back(trescOdpowiedzi.size()-1);   /* .size()-1 to indeks ostatniej odpowiedzi czyli dodanej teraz, 
                                                                            dodajemy go do tablicy prawidlowych odpowiedzi*/
    }
    void wypiszPytanieOdpowiedz() { // wypisanie pytania wraz z odpowiedzia
        cout << trescPytania << "\n";
        getOdpowiedzi();
    }
    void dodajUdzielonaOdpowiedz(int _indexWybranejOdp) { //dodajemy odpowiedz do tablicy udzielonych odpowiedzi na zasadzie A=0, B=1, ...
        udzieloneOdpowiedzi.push_back(_indexWybranejOdp);
    }
    void dodajUdzielonaOdpowiedz(char _literaWybranejOdp) { //dodajemy odpowiedz do tablicy udzielonych odpowiedzi na zasadzie A=0, B=1, ...
        _literaWybranejOdp = toupper(_literaWybranejOdp);
        if(_literaWybranejOdp<65 || _literaWybranejOdp > 90) {
            cout << "nieprawidlowa litera";
            return;
        }
        udzieloneOdpowiedzi.push_back(_literaWybranejOdp-65);
    }
    void ocen() {
        ocenyOdp.resize(trescOdpowiedzi.size());
        fill(ocenyOdp.begin(), ocenyOdp.end(), -1);
            for(int i=0; i<udzieloneOdpowiedzi.size();i++) { //wpisanie do tablicy OcenyOdp wartosci wypelnionych odpowiedzi
                if(find(prawidloweOdpowiedzi.begin(), prawidloweOdpowiedzi.end(), udzieloneOdpowiedzi[i]) != prawidloweOdpowiedzi.end()) {
                    ocenyOdp[udzieloneOdpowiedzi[i] ] = OK_MARKED; // jesli odpowiedz jest prawidlowa dodajemy flage OK_MARKED
                }
                else {
                    ocenyOdp[udzieloneOdpowiedzi[i] ] = BAD_MARKED; // jesli odpowiedz jest bledna dodajemy flage BAD_MARKED
                }
            }
            for(int j=0; j<trescOdpowiedzi.size(); j++) { // wpisanie do tablicy ocenyOdp pozostalych wartosci (niewypelnionych odpowiedzi)
                if(ocenyOdp[j] == -1) { // jesli odpowiedz nie zostala oceniona
                    if(find(prawidloweOdpowiedzi.begin(), prawidloweOdpowiedzi.end(), j) != prawidloweOdpowiedzi.end()) {
                        ocenyOdp[j] = OK_UNMARKED;
                    } // jesli odpowiedz jest prawidlowa dodajemy flage OK_UNMARKED
                    else { // w przeciwnym wypadku dodajemy flage BAD_UNMARKED
                        ocenyOdp[j] = BAD_UNMARKED;
                    }
                }
            }
    }
    void statystykaOdpowiedzi() {
        ocen();
        int poprawne = 0, bledne = 0, pusteDobreOdp = 0, pusteZleOdp = 0;
        for(int i=0; i<ocenyOdp.size();i++) { 
            switch(ocenyOdp[i]) {
                case OK_MARKED:
                poprawne++;
                break;
                case OK_UNMARKED:
                pusteDobreOdp++;
                break;
                case BAD_UNMARKED:
                pusteZleOdp++;
                break;
                case BAD_MARKED:
                bledne++;
                break;
            }
        }

        pusteDobreOdp = prawidloweOdpowiedzi.size() - poprawne;
        pusteZleOdp = trescOdpowiedzi.size() - poprawne - bledne - pusteDobreOdp;

        cout << "poprawne: " << poprawne << " bledne: " << bledne << endl;
        cout << "nie zaznaczono " << pusteDobreOdp << " prawidlowych odpowiedzi oraz " << pusteZleOdp << " blednych odpowiedzi";
    }
    
};

class Oceniacz : public Pytanie {

    virtual int punktyZaOdp();

};

class OceniaczPojedynczyWybor : public Oceniacz {
    OceniaczPojedynczyWybor() {}
    ~OceniaczPojedynczyWybor() {}

    int punktyZaOdp() {
        cout << "kk\n";
        bool zaznaczonoZle = false;
        int dobreOdp = 0;
        for(int i=0; i<ocenyOdp.size(); i++) {
            if(ocenyOdp[i]==OK_MARKED)
                dobreOdp++;
            if(ocenyOdp[i]==BAD_MARKED)
                zaznaczonoZle = true;
        }
        if(!zaznaczonoZle && dobreOdp == 1)
            return 1;
        else
            return 0;  
    }
};


class OceniaczWielokrotnyWybor : public Oceniacz {
    OceniaczWielokrotnyWybor() {}
    ~OceniaczWielokrotnyWybor() {}
    int punktyZaOdp() {
        bool zaznaczonoZle = false;
        int dobreOdp = 0;
        if(udzieloneOdpowiedzi.size() == 0)
            return 0;
        
        for(int i=0;i<ocenyOdp.size(); i++) {
            if(ocenyOdp[i] == OK_MARKED)
                dobreOdp++;
            if(ocenyOdp[i] == BAD_MARKED)
                return 0;
        }

        if(dobreOdp == prawidloweOdpowiedzi.size() && zaznaczonoZle == false)
            return 2;
        if(dobreOdp>0 && zaznaczonoZle == false)   
            return 1;
        
    }
};

int main() {

    Pytanie p1;
    p1.setTresc("Jaka flage ma Polska?");
    p1.addOdpowiedz("bialo-niebieska", false); //A
    p1.addOdpowiedz("bialo-czarna", false); // B
    p1.addOdpowiedz("bialo-czerowona", true); // C poprawna
    p1.addOdpowiedz("czerwono-biala", false); // D
    p1.addOdpowiedz("prostokatna", true); // E poprawna
    p1.addOdpowiedz("trojkatna", false); // F

    p1.wypiszPytanieOdpowiedz();

    cout << "dla przykladu wybieramy odpowiedzi A i C. A jest bledna, C - prawidlowa. Zostaja 4 puste odpowiedzi w tym 1 bledna\n";
    p1.dodajUdzielonaOdpowiedz('a');
    p1.dodajUdzielonaOdpowiedz(2); // odp. C
    p1.statystykaOdpowiedzi();
    cout << endl; p1.ocen();
    return 0;
}