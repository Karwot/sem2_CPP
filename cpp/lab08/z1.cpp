#include <iostream >
 using namespace std;
struct P{ 
    static int licznik;
    void pisz(){ 
        cout << "pisze sobie\n" << licznik; 
        }
      
    P(){ 
       licznik++;
    }
    };

 void f_wartosc(P p){ p.pisz(); }



int P::licznik = 0;

int main(){ 
      //f_wartosc(utworz()); 
       f_wartosc(P()); 
      // f_stala_referencja(utworz()); 
      return 0;
}
