#include <iostream>
#include <cstdio>
#include<bits/stdc++.h> 
#include <string>
using namespace std;

class Podatek {
    private:
    static float prog_kwotowy[2];
    static float stopa_procentowa[2];
    static float kwota_wolna;
    float podstawa_opodatkowania;
    float ulga_podatkowa = 0;
    public:
    
    Podatek(float kwota = 0) {
        podstawa_opodatkowania = kwota;
    };
    static void ustawKwoteWolna(float value) {
        kwota_wolna = value;
    }
    static void ustawProgKwotowy(int index, float wartosc) {
        prog_kwotowy[index] = wartosc;
    }
    static void ustawProcent(int index, float wartosc) {
        stopa_procentowa[index] = wartosc;
    }
    void setPodstawa(float wartosc) {
        podstawa_opodatkowania = wartosc;
    }
    void dodajUlge(float wartosc) {
        ulga_podatkowa += wartosc;
    }
    float getKwotaWolna() {
        return kwota_wolna;
    }
    float getPodstawa() {
        return podstawa_opodatkowania;
    }
    int getProgKwotowy() {
        if(podstawa_opodatkowania-ulga_podatkowa>prog_kwotowy[1]) // czyli kwota znajduje się w 2 progu podatkowym
            return 1;
        else if(podstawa_opodatkowania-ulga_podatkowa<=prog_kwotowy[0]) // czyli kwota mieści się w 1 progu podatkowym
            return 0;
        return 0;
    }
    
    float kwotaPodatku() {
       /*
        if(podstawa_opodatkowania-ulga_podatkowa<=prog_kwotowy[1]) {
                if(podstawa_opodatkowania-ulga_podatkowa>kwota_wolna) {
                    return 1.0*(podstawa_opodatkowania-kwota_wolna-ulga_podatkowa)*(stopa_procentowa[0]/100);
                } else if(podstawa_opodatkowania-ulga_podatkowa<=kwota_wolna) {
                    return 0;
                }
            }
        else if(podstawa_opodatkowania-ulga_podatkowa>prog_kwotowy[1]) {
            return 1.0*(prog_kwotowy[1]-ulga_podatkowa)*(stopa_procentowa[0]/100)+(podstawa_opodatkowania-prog_kwotowy[1])*(stopa_procentowa[1]/100);
        }
        return 0;*/

        if(getProgKwotowy()>0) {
             return 1.0*(prog_kwotowy[1]-ulga_podatkowa)*(stopa_procentowa[0]/100)+(podstawa_opodatkowania-prog_kwotowy[1])*(stopa_procentowa[1]/100);
        } 
        else if(getProgKwotowy()==0) {
            if(podstawa_opodatkowania-ulga_podatkowa<=kwota_wolna) {
                return 0;
            }
            else {
                return 1.0*(podstawa_opodatkowania-kwota_wolna-ulga_podatkowa)*(stopa_procentowa[0]/100);
            }
        }

        return 0;
    }
    const string toString() {
        int indx= 0;
        string result = to_string(kwotaPodatku());
        while(result[indx]!='.') {
            indx++;
        }
        return result.substr(0,indx+3);
    }
    const string toXML() {
        return "<amount>"+to_string(podstawa_opodatkowania)+"</amount>\n<tax>"+toString()+"</tax>";
    }
    void opis() {
        cout << "Dla kwoty " << podstawa_opodatkowania << " z ulga " << ulga_podatkowa <<
         " podatek wynosi " << kwotaPodatku() << ". Jest to " << getProgKwotowy()+1 << " prog podatkowy" <<  endl;
    }
};

float Podatek::kwota_wolna { 8000 };
float Podatek::prog_kwotowy[] {0 , 85528};
float Podatek::stopa_procentowa[] {18, 32};

int main() {
    cout << fixed << setprecision(2);

    Podatek p2[5];
    
    p2[0].ustawProgKwotowy(1,85528);//ustawianie kwoty drugiego progu podatkowego
    p2[0].ustawProcent(0,18); // wartość procentowa podatku na 1 progu 
    p2[0].ustawProcent(1,32); // wartość procentowa podatku dla 2 progu podatkowego

    p2[0].setPodstawa(87650);
    p2[0].dodajUlge(700);
    
    p2[1].setPodstawa(3000);
    p2[1].opis();

    
    p2[0].opis();
    p2[2].setPodstawa(125000);
    p2[2].opis();
    cout << "podatek: " <<  p2[0].kwotaPodatku();
    cout << endl << "toString " << p2[0].toString() << endl;
    cout << "toXML(): " << endl << p2[0].toXML();
    return 0;
}