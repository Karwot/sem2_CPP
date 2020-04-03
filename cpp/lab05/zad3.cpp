#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
// concatenation
string concat(string first, string second) {
    return first+second;
}
// example 2: ala ma kota => AlaMaKota
string firstToUpperCase(string st) {
    st[0] = (char)toupper(st[0]);
    int spacebarCount = 0;
    for(int i=0; i<st.length(); i++) {
        if(st[i]==32) {
            spacebarCount++;
            st[i+1] = (char)toupper(st[i+1]);
            for(int j=i; j<st.length(); j++) {
                st[j] = st[j+1];
            }
        }   
    }
    st.resize(st.length()-spacebarCount);
    //cout << st.length();
    return st;
}
// function returns substring taken from string "st", int "start" - first index of substring, int "end" - last index of substring
// if int "end" is less than 0, the substring stops at the very end of string "st" 
string substring(string st, int start, int end) {
    string result = "";
    if(end<0) {
        for(int i=start; i<st.length(); i++)
            result+=st[i];
    }
    else {
        for(int i=start; i<=end; i++)
            result+=st[i];
    }
    return result;
}
// if string "st" containts substring "subs", the function returns index where the first appearance begins. Otherwise it returns 0
int search(string st, string subs) {
    int tempCounter = 0;
    for(int i=0; i<st.length(); i++) {
       if(st[i]==subs[0]){
            if(substring(st, i, (i+(subs.length())-1) ) == subs) {    
                //cout << "substring at: " << i << endl;
                return i;
            }    
       } 
    }
    return 0;
}

int main() {
    string s;
    cout << "Write your sentence: ";
    getline(cin, s);
    cout << firstToUpperCase(s);
    cout << endl << substring(s, 2, -3);
    cout << endl << "substing \"ma\" starts at index: " << search(s, "ma");

    return 0;
}