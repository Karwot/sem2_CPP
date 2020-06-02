#include<iostream>
#include<vector>
using namespace std;

class Ulamek
{
    private:
		int licznik;
		int mianownik;
    public:
		Ulamek():licznik(0), mianownik(0) {}
		Ulamek(int licznik_, int mianownik_): licznik(licznik_), mianownik(mianownik_) {}
		void setLicznik(int licznik_) {
			licznik = licznik_;
		}
		void setMianownik(int mianownik_) {
			mianownik = mianownik_;
		}
		const int getLicznik() {
			return licznik;
		}
		const int getMianownik() {
			return mianownik;
		}
		friend ostream& operator<<(ostream& out, const Ulamek& a);
		friend Ulamek operator/(const Ulamek &a, const Ulamek &b);
};

class UlamekExc
{
    protected:
		Ulamek err;
    public:
		UlamekExc(Ulamek a): err(a){}
		void virtual blad() = 0;
};

class ZeroMian : public UlamekExc
{
    protected:
		int zero;
    public:
		ZeroMian(Ulamek a, int z_):UlamekExc(a), zero(z_){};

      void virtual blad()
      {
          cout <<  "Zero w mianowniku" << endl;
      }
};

class UlamekZero : public UlamekExc
{
    protected:
      int zero;
    public:
      UlamekZero(Ulamek a, int z_):UlamekExc(a), zero(z_){};

      void virtual blad()
      {
          cout <<  "Ulamek przez ktory dzielimy jest rowny zero" << endl;
      }
};

ostream& operator<<(ostream& out, const Ulamek& a) {
    if(a.mianownik==0) throw ZeroMian(a, a.mianownik);
    return out << a.licznik << "/"<< a.mianownik;
}

Ulamek operator/(const Ulamek &a, const Ulamek &b) {
    if(b.licznik==0) {
     throw UlamekZero(b, b.licznik);
    }

    int licznik_, mianownik_;
    licznik_ = a.licznik * b.mianownik;
    mianownik_ = a.mianownik * b.licznik;
    Ulamek iloraz(licznik_, mianownik_);
    return iloraz;
}


int main()
{
    vector<Ulamek> lista;
    lista.push_back(Ulamek(5, 4));
    lista.push_back(Ulamek(2, 7));
    lista.push_back(Ulamek(8, 3));
    lista.push_back(Ulamek(0, 4));
    lista.push_back(Ulamek(6 ,0));

  try {
    cout << "--zwykly ulamek: \n" << lista[0] << endl;
  } catch (UlamekExc &a) {
    a.blad();
  }

    try {
			cout<< "--ulamek w mianowniku ma licznik = 0:\n" <<  lista[2]<< " : " << lista[3] << " = ";
			cout << lista[2]/lista[3] << endl;
    }catch(UlamekExc &a) {
        a.blad();
    }
    
    try {
        cout << "--Ulamek w ktorym mianownik = 0 :\n" << lista[4] << endl;
    }catch(UlamekExc &a) {
        a.blad();
    };
    
  return 0;  
}
