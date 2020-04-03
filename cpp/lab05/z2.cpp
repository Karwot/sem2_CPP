#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char mostCommonChar(string st) {
    int asciiCharacters[128] = { 0 };

    for(int i=0;i<st.length(); i++) {
        int tmp = st[i];
        asciiCharacters[tmp]++;
    }
    int maxIndex = 0;

    for(int i=0; i<128; i++) {
        if(asciiCharacters[i]>asciiCharacters[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}

int wordCount(string st) {
    int counter = 1;
    for(int i=0; i<st.length(); i++) {
        st[i] = tolower(st[i]);
        if(st[i]<97 || st[i]>122 )
            counter++;
    }
    return counter;
}

int main()  {
    string napis;
    cout << "Your senence: ";
    getline(cin, napis);
    cout << "The most common sign in this sentence: " << mostCommonChar(napis) << endl;
    cout << "Amount of words: " << wordCount(napis);
    return 0;
}