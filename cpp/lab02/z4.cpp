#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <random>
using namespace std;

int liczbaLosowa(int a, int b) {
        return rand() % b + a;
}

double liczbaLosowa(double a, double b) {
        double r = ((double)rand()/(double)(RAND_MAX/(b-a)));
        return a+r;
}

int main() {

srand (time(NULL));

cout << liczbaLosowa(1,7) << "\n";
cout << liczbaLosowa(5.1,5.3) << "\n";

return 0;
}