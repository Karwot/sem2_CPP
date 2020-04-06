#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

long long int silnia(int n) {
        if(n<2)
                return 1;
        return n*silnia(n-1);
}

int main() {
    for(int i=0; i<=5; i++) {
                    cout << "silnia z " << i << "= " << silnia(i) << "\n";
    }

    return 0;
}