#include <iostream>
#include <cstdio>
using namespace std;

void filter(int t[], int n, bool (*f)(int)){
    for(int i=0; i<n;i++)
       if(f(t[i]))
            cout << t[i] << " ";
}

//example filter
bool lessThan0(int a) {
    return a<0;
}

int main() {

    int arr[] = { -1, 5, 12, -7 };
    filter(arr, 4, lessThan0);

    return 0;
}