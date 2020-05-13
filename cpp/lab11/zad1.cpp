#include <iostream>
#include <string>
using namespace std;

class Przedmiot {
    private:
        string nazwa;
        float szerokosc;
        float waga;
    public:
        Przedmiot() : nazwa(""), szerokosc(0), waga() { cout << "Konstruktor klasy Przedmiot\n"; }
        Przedmiot(string _nazwa, float _szerokosc, float _waga) : nazwa(_nazwa), szerokosc(_szerokosc), waga(_waga)  { "Konstruktor klasy Przedmiot\n"; }
        ~Przedmiot() { cout << "desktruktor klasy Przedmiot\n"; }
    void setNazwa(string _nazwa) {
        nazwa = _nazwa;
    }
    void setSzerokosc(float _szerokosc) {
        szerokosc = _szerokosc;
    }
    void setWaga(float _waga) {
        waga = _waga;
    }
    string getNazwa() {
        return nazwa;
    }
    float getSzerokosc() {
        return szerokosc;
    }
    float getWaga() {
        return waga;
    }
};

class Ksiazka : public Przedmiot {
    private: 
        string autor;
    public:
        Ksiazka() : autor("") { cout << "konstruktor klasy Ksiazka\n"; }
        Ksiazka(string _autor) : autor(_autor) { cout << "konstruktor klasy Ksiazka\n"; }
        Ksiazka(string _nazwa, float _szerokosc, float _waga, string _autor) : autor(_autor)  {
            this->setNazwa(_nazwa);
            this->setSzerokosc(_szerokosc);
            this->setWaga(_waga);
            cout << "konstruktor klasy Ksiazka\n";
        }
        ~Ksiazka() { cout << "destuktor klasy Ksiazka\n"; }
        void setAutor(string _autor) {
            autor = _autor;
        }
        string getAutor() {
            return autor;
        }
};

class Plyta : public Przedmiot {
    private:
        float zajetaPrzestrzen;
    public:
        Plyta() { cout << "Konstruktor klasy plyta\n"; }
        ~Plyta() { cout << "destruktor klasy plyta\n"; }
    
        virtual void setZajetaPrzestrzen(float n ) { zajetaPrzestrzen = n; }
        virtual float getZajetaPrzestrzen() { return zajetaPrzestrzen; }
};

class DVD : public Plyta {
    public:
    DVD() { cout << "Konstruktor DVD\n"; }
    ~DVD() {}
};

class CD : public Plyta {
    public:
    CD() { cout << "Konstruktor CD\n";}
    ~CD() {}
};

class Polka {
    private:
        float maxSzerokosc;
        float maxNosnosc;
        float zajetaPowierzchnia;
        float zajetaWaga;
    public:
        Polka() {
             cout << "Konstruktor klasy Polka\n";
        }
        Polka(float _maxSzerokosc, float _maxNosnosc) : maxSzerokosc(_maxSzerokosc), maxNosnosc(_maxNosnosc), zajetaPowierzchnia(0), zajetaWaga(0) {
             cout << "Konstruktor klasy Polka\n";
        }
        ~Polka() { cout << "destruktor klasy Polka\n"; }
        void dodajPrzedmiot(Przedmiot a) {
            if( ( (zajetaPowierzchnia+a.getSzerokosc() )>maxSzerokosc) || ( (zajetaWaga+a.getWaga()) > maxNosnosc)  ) {
                cout << "Przedmiot nie zmiesci sie na półce.\n";
            } else {
                zajetaPowierzchnia += a.getSzerokosc();
                zajetaWaga += a.getWaga();
            }
        }
        void wypiszZajetaPrzestrzen() {
            cout << "Szerokosc:" << zajetaPowierzchnia << "\n"; 
            cout << "Waga: " << zajetaWaga << "\n";
        }
};

int main() {
    Ksiazka ksiazka1;
    Polka polka1(50, 20);
    ksiazka1.setWaga(40);
    ksiazka1.setSzerokosc(40);

    CD plyta1;
    plyta1.setSzerokosc(10);
    plyta1.setWaga(5);

    polka1.dodajPrzedmiot(plyta1);
    polka1.wypiszZajetaPrzestrzen();
    polka1.dodajPrzedmiot(ksiazka1);
    polka1.wypiszZajetaPrzestrzen();


    return 0;
}