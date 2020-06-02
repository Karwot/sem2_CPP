#include <iostream>
template<typename T1, typename T2>
auto iloczyn(T1 a, T2 b) {
    return a*b;
}

template<typename T1, typename T2> 
auto operator*(T1 a, T2 b) {
    return a*b;
}

int main () {
    std::cout << "funkcja iloczyn: 5*4 = " << iloczyn(5,4) << "\n 1.5*3 = " << iloczyn(1.5, 3) << "\n";
    
    std::cout << "przeciazenie operatora: 7*3 = " << 7*3 << "\n" << "5.2*3 = " << 5.2*3;
    return 0;
}