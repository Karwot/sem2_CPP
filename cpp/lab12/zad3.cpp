#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Pytanie {
private:
    string trescPytania;
    vector<string> trescOdpowiedzi;
    vector<int> prawidloweOdpowiedzi;
    vector<int> udzieloneOdpowiedzi;
protected:
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
            for(int i=0; i<udzieloneOdpowiedzi.size();i++) {
                if(find(prawidloweOdpowiedzi.begin(), prawidloweOdpowiedzi.end(), udzieloneOdpowiedzi[i]) != prawidloweOdpowiedzi.end()) {
                    ocenyOdp[udzieloneOdpowiedzi[i] ] = OK_MARKED; // jesli odpowiedz jest prawidlowa dodajemy flage OK_MARKED
                }
                else {
                    ocenyOdp[udzieloneOdpowiedzi[i] ] = BAD_MARKED; // jesli odpowiedz jest bledna dodajemy flage BAD_MARKED
                }
            }
            for(int j=0; j<trescOdpowiedzi.size(); j++) {
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

class Osoba { // osoba egzaminowana
    protected:
    string imie;
    string nazwisko;
};

class Test : public Osoba  {
    private:
        vector<Pytanie> pytania;
    public:
    Test() {}
    ~Test() {}

    void dodajPytanie (Pytanie nowe_) {
        pytania.push_back(nowe_);
    }
    void wypiszJednoPytanie(int index_) {
        pytania[index_].wypiszPytanieOdpowiedz();
    }
    void wypiszPytania() {
        for(int i=0; i<pytania.size(); i++) {
            pytania[i].wypiszPytanieOdpowiedz();
        }
    }
    void setImie(string imie_) {
        imie = imie_;
    }
    void setNazwisko(string nazwisko_) {
        nazwisko = nazwisko_;
    }
    void zmienDaneOsoby(string imie_, string nazwisko_) {
        imie = imie_;
        nazwisko = nazwisko_;
    }
    void wypiszDaneOsoby() {
        cout << imie << " " << nazwisko;
    }

};

int main() {

    Test t1;
    t1.zmienDaneOsoby("Jan", "Kowalski");
    Pytanie lista[3];
    lista[0].setTresc("Ile wojewodztw jest w Polsce?");
    lista[0].addOdpowiedz("15", false);
    lista[0].addOdpowiedz("16", true);
    lista[0].addOdpowiedz("17", false);
    
    lista[1].setTresc("Jaka flage ma Polska?");
    lista[1].addOdpowiedz("bialo-niebieska", false);
    lista[1].addOdpowiedz("bialo-czarna", false); 
    lista[1].addOdpowiedz("bialo-czerowona", true); 
    lista[1].addOdpowiedz("czerwono-biala", false); 
    lista[1].addOdpowiedz("prostokatna", true); 
    lista[1].addOdpowiedz("trojkatna", false); 


    t1.dodajPytanie(lista[0]);
    t1.dodajPytanie(lista[1]);
    t1.wypiszDaneOsoby(); cout << endl;
    t1.wypiszPytania();

    cout << "\nwypisanie pojedynczego pytania: \n"; t1.wypiszJednoPytanie(1);
    return 0;
}