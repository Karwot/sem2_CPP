#include <cstdio>
#include <iostream>
#include <cstdarg>
#include <cmath>
using namespace std;

int sumOfArgs(int amountOfArgs, ...) {
    va_list valist;
    int i=0, sum = 0;
    va_start(valist, amountOfArgs);
    while(i<amountOfArgs){
        sum+= va_arg(valist, int);
        i++;
    }
    va_end(valist);
    return sum;
}

float average(int amountOfArgs, ...) {
    va_list valist;
    int sum = 0, i = 0;
    va_start(valist, amountOfArgs);
        while(i<amountOfArgs) {
            sum += va_arg(valist, int);
            i++;
        }
    va_end(valist);
    return (1.0*sum)/amountOfArgs;
}

float geometric(int amountOfArgs, ...) {
    va_list valist;
    int sum = 1, i = 0;
    va_start(valist, amountOfArgs);
        while(i<amountOfArgs) {
            sum *= va_arg(valist, int);
            i++;
        }
    va_end(valist);

    return pow(sum, 1.0/amountOfArgs); // sum^(1/amount)
}

float harmonic(int amountOfArgs, ...) {
    float bottomSum = 0;
    va_list valist;
    va_start(valist, amountOfArgs);

    int i=0; 
    while(i<amountOfArgs) {
        bottomSum += 1.0/va_arg(valist, int);
        i++;
    }
    
    va_end(valist);
    return (1.0*amountOfArgs)/bottomSum;
}



int main() {

    cout << "sum: " << sumOfArgs(4, 2, 1, 3, 5) << "\n";
    cout << "average: " << average(4, 2, 1, 3, 5) << "\n";
    cout << "gometric mean: " << geometric(4, 2, 1, 7, 5) << "\n";
    cout << "harmonic mean: " << harmonic(4, 2, 1, 3, 5) << "\n";

    return 0;
}