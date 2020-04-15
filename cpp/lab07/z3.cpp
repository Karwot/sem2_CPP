#include <iostream>
#include <string>
using namespace std;

class Data {
    private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

   public:
    unsigned int getDay() {
        return day;
    }
    unsigned int getMonth() {
        return month;
    }
    unsigned int getYear() {
        return year;
    }

     void setYear(unsigned int y) {
        year = y;
    }

    void setMonth(unsigned int m) {
        if(m>12) {
            cout << "nieodpowiednia wartosc miesiaca" << endl;
            month = 0;
            return;
        }
        month = m;
    }

    void setDay(unsigned int d) {
        if(this->month == 2) 
            if(d>29) {
                cout << "nieprawidlowa wartosc dzien" << endl;
                return;
            }
        if(this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
            if(d>30) {
                cout << "nieprawidlowa wartosc dzien" << endl;
                return;
            }
        if(d>31) {
            cout << "nieprawidlowa wartosc dzien";
            return;
        }
        day = d;
    }

    void initDate(unsigned int d, unsigned int m, unsigned int y) {
        setYear(y);
        setMonth(m);
        setDay(d);
    }

    string toString() {
        if(month<10)
            return to_string(day) + ".0" + to_string(month) + "." + to_string(year);
        return to_string(day) + "." + to_string(month) + "." + to_string(year);    
    }
    string toXML() {
        return "<day>" + to_string(day) + "</day>\n<month>"+to_string(month)+"</month>\n<year>"+to_string(year)+"</year>";
    }

};

class Faktura {
    private: 
    string nazwa_zlecenia;
    Data data_zlecenia;
    string numer_faktury;

    public: 
    void init(string name, string num, unsigned int d, unsigned int m, unsigned int y) {
        nazwa_zlecenia = name;
        numer_faktury = num;
        data_zlecenia.initDate(d,m,y);
    }

    string toString() {
        return "Faktura nr "+numer_faktury+"\n"+"Nazwa zlecenia: "+nazwa_zlecenia+"\n"+"Data: "
            +to_string(data_zlecenia.getDay()) +"."+ to_string(data_zlecenia.getMonth())+"."+to_string(data_zlecenia.getYear());
    }

    string toXML() {
        return "<name>"+nazwa_zlecenia+"</name>\n<nr>"+numer_faktury+"</nr>\n<date>"+data_zlecenia.toString()+"</date>";
    }
};

int main() {
    //zadanie 2
    Data d;
    d.initDate(17, 3, 2012);
    d.setDay(15);
    d.setMonth(4);
    d.setYear(2020);

    cout << "\nWypisanie daty przy pomocy: " << endl;
    cout << "Funkcji typu get: \n" <<  d.getDay() << "." << d.getMonth() << "." << d.getYear() << endl;
    cout << "Funkcji toString: \n" << d.toString() << endl;
    cout << "Funkcji toXML: \n" << d.toXML();

    //zadanie 3 
    Faktura f1;
    f1.init("zlecenie1", "3", 15, 4, 2020);
    cout << "Faktura w postaci tekstowej:\n" << f1.toString() << endl;
    cout << "\nFaktura w postaci XML:\n" << f1.toXML();
    return 0;
}