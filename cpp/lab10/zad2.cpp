#include <iostream>
using namespace std;

class Date {
    //private:
    int day;
    int month;
    int year;
    public: 
    Date() : day(0), month(0), year(0) {}
    Date(int _day, int _month, int _year) : day(_day), month(_month), year(_year) {}

    Date & operator++() { 
         if(day==31) {
            if(month==12) {
                day = 1;
                month = 1;
                year++;
            } else {
            day=1;
            month++; 
            }
        }
        else 
            day++;
        return *this;
    }
    friend bool operator<(const Date& d1, const Date& d2);
    friend ostream & operator << (ostream &out, const Date &d);
    friend istream & operator << (istream &in, Date &d);

};

istream & operator << (istream &in, Date &d) {
    cout << "dzien:\n";
    in >> d.day;
    cout << "miesiac:\n";
    in >> d.month;
    cout << "rok:\n";
    in >> d.year;
    return in;
}

ostream & operator << (ostream &out, const Date &d) {
    if(d.day<10)
    out << 0;
    out << d.day << ".";
    if(d.month<10)
        out << 0; 
    out << d.month << "." << d.year;
    return out;
}

bool operator<(const Date& d1, const Date& d2) {
    if(d1.year!=d2.year)
        return d1.year<d2.year;
    if(d1.month!=d2.month)
        return d1.month<d2.month;

    return d1.day<d2.day;
}

void cout7followigDays(Date d) {
    for(int i=0; i<7;i++) {
        cout << ++d << endl;
    }
}

void compareAndCout(Date d1, Date d2) {
    cout << "Data pozniejsza z podanych podanych: ";
    if(d1<d2) {
        cout << d2 << "\n7 dni po tej dacie: \n"; 
        cout7followigDays(d2);
    }
    else {
        cout << d1 << "\n7 dni po tej dacie: \n";
        cout7followigDays(d1);
    } 
}

int main() {
    Date d1(31,12,2012);
    Date d2(17,3,2010);
    Date d3;
    cout << "Wynik programu dla gotowych wartosci: \n";
    cout << "\nData nr 1:" <<  d1 << " Data nr1 +1 dzien: " << ++d1 <<  "\nData nr2: " << d2 << "\nKonstruktor domyslny: " << d3 << "\n";
    
    compareAndCout(d1, d2);

    Date u1, u2;

    cout << "________________________________\n";
    cout << "dla wartosci podanych przez uzytkownika: \n";
    cout << "Data nr 1: \n";
    cin << u1;
    cin << u2;
    compareAndCout(u1, u2);
    return 0;
}