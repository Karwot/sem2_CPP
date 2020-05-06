#include <iostream>
#include <string>
using namespace std;

class Name {
//private:
    string imie;
    string nazwisko;
public:
    Name() {} 
    Name(string _imie, string _nazwisko) : imie(_imie), nazwisko(_nazwisko) {}

    string initials() {
        string result ="";
        result += imie[0];
        result += nazwisko[0];
        return result;
    }

   friend bool operator<(const Name& data1, const Name& data2);
   friend ostream & operator << (ostream &out, const Name &n);
   friend istream & operator >> (istream &in, Name &n);

};

ostream & operator << (ostream &out, const Name &n) {
    out << n.imie + " " + n.nazwisko;
    return out;
};

istream & operator >> (istream &in, Name &n) {
    cout << "Imie: " << endl;
    in >> n.imie;
    cout << "Nazwisko: " << endl;
    in >> n.nazwisko;
    return in;
}

bool compareStrings(string str1, string str2) { // funkcja zwraca true jesli napis str1 poprzedza alfabetycznie napis str2 lub gdy są te same
    int i = 0;
    do {
        if(str1[i]!=str2[i])
            return str1[i]<str2[i];
        i++;
    } while ( str1[i]!=str2[i] && i < max( str1.length(), str2.length() )  );
    return str1[0] < str2[0];
};

bool operator<(const Name& data1, const Name& data2) {   
    if(data1.nazwisko==data2.nazwisko)
        return compareStrings(data1.imie, data2.nazwisko);

    return compareStrings(data1.nazwisko, data2.nazwisko);
};

int main() {

    Name a1("Jan", "Kowalski");
    Name a2("Adam", "Nowak");

    cout << "Gotowe dane: \nOsoba nr 1: " << a1 << endl << "Osoba nr 2: " << a2 << endl;
    cout << "Inicjaly osoby wystepujacej wczesniej w alfabecie: " << endl;
    if(a1<a2)
        cout << a1.initials();
    else
        cout << a2.initials();
    cout << "\n_______________________\n Dane do wprowadzenia: " << endl;

    Name n1, n2;
    cout << "dane osoby nr1:" << endl;
    cin >> n1;
    cout << "dane osoby nr2:" << endl;
    cin >> n2;
    cout << n1.initials() << endl;
    cout << "inicjaly osoby wypadajacej wczesniej w alfabecie: ";
    if(n1<n2)
        cout << n1.initials();
    else
        cout << n2.initials();

    return 0;
}