#include <cstdio>
#include <iostream>
using namespace std;

void rev(int* arr, int n) {
    int rindx = n-1;
    int tmp[n];
    for(int i=0; i<n; i++) {
        tmp[i] = arr[rindx];
        rindx--;
    }
    for(int i=0; i<n; i++) {
        arr[i] = tmp[i];
    }
}

void toRight(int *arr, int n) {
        int tmp[n];
        for(int i=0; i<n; i++)
                tmp[i] = arr[i];
        arr[0] = tmp[n-1];
        arr[n-1] = tmp[n-2];
        for(int j=1; j<n-1; j++)
                arr[j] = tmp[j-1];
}

void sortArr(int* arr, int n) {
        for(int i=0;i<n-1;i++) {
                for(int j=i+1;j<n;j++) {
                        if(arr[i]>arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
}

void printArr(int* arr, int n) {
        for(int i=0; i<n; i++)
                cout << arr[i] << " ";
        cout << "\n";
}

int main()
{
        int t1[10] = { 4, 10, 15, 13, 44, 85, 6, 7, 8, 9 };

        printArr(t1,10);
        rev(t1, 10);
        printArr(t1, 10);
        toRight(t1, 10);
        printArr(t1,10);
        sortArr(t1, 10);
        printArr(t1, 10);
return 0;
}