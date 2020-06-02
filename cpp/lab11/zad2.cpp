#include <iostream>
#include <string>
using namespace std;

bool compareStrings(string str1, string str2) { // funkcja zwraca true jesli napis str1 poprzedza alfabetycznie napis str2 lub gdy są te same
    int i = 0;
    do {
        if(str1[i]!=str2[i])
            return str1[i]<str2[i];
        i++;
    } while ( str1[i]!=str2[i] && i < max( str1.length(), str2.length() )  );
    return str1[0] < str2[0];
};

class Adres {
    protected:
        string ulica;
        string numerDomu;
        string miasto;
    public:
    Adres() {}
    ~Adres() {}
    string getUlica() {
        return ulica;
    }
    string getNumerDomu() {
        return numerDomu;
    }
    string getMiasto() {
        return miasto;
    }
    void setUlica(string _ulica) {
        ulica = _ulica;
    }
    void setNumerDomu(string _numerDomu) {
        numerDomu = _numerDomu;
    }
    void setMiasto(string _miasto) {
        miasto = _miasto;
    }
    virtual void podajDane() =0;
};

class Pacjent : public Adres {
protected:
    string imie;
    string nazwisko;
    string PESEL;
public:
    Pacjent () : imie(""), nazwisko(""), PESEL("") {}
    Pacjent (string _imie, string _nazwisko, string _PESEL) : imie(_imie), nazwisko(_nazwisko), PESEL(_PESEL) {}
    Pacjent (const Pacjent& old)  {
        imie = old.imie;
        nazwisko = old.nazwisko;
        PESEL = old.PESEL;
    }
    ~Pacjent() {}

    string toString() {
        return "imie: " + this->imie + " nazwisko: " + this->nazwisko + " PESEL:" + this->PESEL + " miasto: " + getMiasto() + " ulica: " + getUlica() + "nr domu:" + getNumerDomu() +"\n";
    }
    void setImie(string _imie) {
        imie = _imie;
    }
    void setNazwisko(string _nazwisko) {
        nazwisko = _nazwisko;
    }
    void setPESEL(string _PESEL) {
        PESEL = _PESEL;
    }
    string getImie() {
        return imie;
    }
    string getNazwisko() {
        return nazwisko;
    }
    void podajDane () {
        cout << "imie: ";
        cin >> imie;
        cout << "nazwisko: ";
        cin >> nazwisko;
        cout << "PESEL: ";
        cin >> PESEL;
    }
    friend ostream& operator << (ostream &out, Pacjent p);
    friend istream& operator >> (istream &in, Pacjent p);
    friend bool operator<(const Pacjent& p1, const Pacjent& p2);
};

bool operator<(const Pacjent& p1, const Pacjent& p2) {
    if(p1.nazwisko == p2.nazwisko)
        return compareStrings(p1.imie, p2.imie);
    return compareStrings(p1.nazwisko, p2.nazwisko);

}


ostream& operator << (ostream &out, Pacjent p) {
    out << p.toString();
    return out;
}
istream& operator >> (istream &in, Pacjent p) {
    cout << "Podaj imie: ";
    in >> p.imie;
    cout << "Podaj nazwisko: ";
    in >> p.nazwisko;
    cout << "Podaj nr PESEL: ";
    in >> p.PESEL;
    return in;
}

class Lekarz : public Pacjent {
    private:
    float pensja;
    bool zeSpecjalizacja;
    public:
    Lekarz() : pensja(0), zeSpecjalizacja(false){}
    Lekarz(float _pensja, bool _zeSpecjalizacja) : pensja(_pensja), zeSpecjalizacja(_zeSpecjalizacja) {}
    ~Lekarz() {}
    void podajDane () {
        cout << "imie: ";
        cin >> imie;
        cout << "nazwisko: ";
        cin >> nazwisko;
        cout << "PESEL: ";
        cin >> PESEL;
        cout << "pensja: ";
        cin >> pensja;
    }
    void setPensja(float _pensja) {
        pensja = _pensja;
    }
    void setSpecjalizacja(float _spec) {
        zeSpecjalizacja = _spec;
    }
    void zwiekszPensje(float punktyProcentowe) {
        pensja += (pensja*punktyProcentowe)/100;
    }

    friend ostream& operator << (ostream& out, Lekarz l);
    friend istream& operator >> (istream& in, Lekarz l);
    //friend operator <(Pacjent const& p, Lekarz const& l);
};
/*    
operator <(Pacjent const& p, Lekarz const& l) {
    if(p.getNazwisko()==l.getNazwisko())
        return compareStrings(p.getImie(), l.getNazwisko());
    return compareStrings(p.getImie(), p.getNazwisko());
}*/

istream& operator >> (istream& in, Lekarz l) {
    cout << "Podaj imie: ";
    in >> l.imie;
    cout << "Podaj nazwisko: ";
    in >> l.nazwisko;
    cout << "Podaj nr PESEL: ";
    in >> l.PESEL;
    return in;
}

ostream& operator << (ostream&out, Lekarz l) {
    out << l.toString();
    out << "Pensja: " << l.pensja << " specjalizacja: ";
    if(l.zeSpecjalizacja == true)
        out << "tak";    
    else
        out << "nie";
    out << "\n";
    return out;
}


int main() {

    Pacjent p1, p2, p3;
    p1.setImie("Jan");
    p1.setNazwisko("Kowalski");
    p1.setPESEL("88112200000");
    p2 = p1;                            // wykorzystanie konstruktora kopiujacego
    p3 = p1;
    cout << "pacjenci: \n" << p1 << p2 << p3 <<  endl;
    p2.setImie("Adam");
    p2.setNazwisko("Nowak");
    p2.setPESEL("12345678988");
    p3.setImie("Anna");
    p3.setPESEL("55555555555");
    cout << "pacjenci po zmianie danych: \n" << p1 << p2 << p3 <<  endl;
    Lekarz l1;
    l1.setImie("Jan");
    l1.setNazwisko("Nowak");
    l1.setMiasto("Katowice");
    l1.setPensja(6000);
    cout << "\nLekarz przed podwyzka pensji:\n" << l1;
    l1.zwiekszPensje(25);                           //zwiekszanie pensji o 25%
    cout << "\nLekarz po podwyzce pensji:\n" << l1;

    Pacjent lista[4];
    lista[0] = p1;
    lista[1] = p2;
    lista[2] = p3;
    lista[3] = l1;

    cout << "\nLista przed posortowaniem: \n";
    for(int i = 0; i<4; i++) {
        cout << lista[i];
    }
    //sortowanie bąbelkowe
    for(int i=0; i<4; i++) {
        for(int j=0; j<3; j++) {
            if(lista[j+1]<lista[j])
                swap(lista[j+1], lista[j]);
        }
    }
    cout << "\nLista nazwisk w kolejnosci alfabetycznej: \n";
    for(int i = 0; i<4; i++) {
        cout << lista[i];
    }

    return 0;
}