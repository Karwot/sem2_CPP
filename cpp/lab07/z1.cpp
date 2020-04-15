#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Punkt {
    private:
        float x;
        float y;
    public:
        void setX(float xToSet) {
            x = xToSet;
        }
        void setY(float yToSeT) {
            y = yToSeT;
        }
        void initPoint(float xToSet, float yToSet) {
            x = xToSet;
            y = yToSet;
        }
        float getX() {
            return x;
        }
        float getY() {
            return y;
        }
};

class Lamana {
    private:
    vector<Punkt> line;

    public:
    // -
    void dodajPunkt(float xToSet, float yToSet) {
        Punkt temp;
        temp.setX(xToSet);
        temp.setY(yToSet);   
        line.push_back(temp);   
    }
    // 
    string toString() {
        string result = "";
        for(int i=0; i<line.size(); i++) {
           result+=  "(" + to_string( line[i].getX() ) + ", " + to_string( line[i].getY() ) + ")\n";
        }
        return result;
    }
    void printPoints() {
         for(int i=0; i<line.size(); i++) {
           cout <<  "(" <<  line[i].getX() << ", " << line[i].getY() << ")\n";
        }
    }
    void przesuOWektor(float toMoveX, float toMoveY) {
         int tmpx, tmpy;
         for(int i=0; i<line.size(); i++) {
            line[i].setX( (line[i].getX()+toMoveX) );
            line[i].setY( (line[i].getY()+toMoveY) );
        }
    }

    bool czyZamknieta() {
        return ( ( line[0].getX() == line[line.size()-1].getX() ) && ( line[0].getY() == line[line.size()-1].getY() ) );
    }

};

int main() {

    Lamana l1;

    l1.dodajPunkt(0, 0);
    l1.dodajPunkt(3, 5);
    l1.dodajPunkt(7, 10); 
    l1.dodajPunkt(0, 0);

    l1.printPoints();
    l1.przesuOWektor(1, 1);
    cout << endl;

    if(l1.czyZamknieta())
        cout << "lamana zamknieta";
    else
        cout << "lamana otwarta";
    

    return 0;
}
