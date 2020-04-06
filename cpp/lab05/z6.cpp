#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void stats(string fileName) {
    ifstream f(fileName);
    char ch;
    int words = 1, lines = 1;
    int wordLen = 0;
    while(f) {
        f.get(ch);
        wordLen++;
        ch = tolower(ch);
        if(ch<97 || ch>122 ){
       // if(ch==' ' || ch=='\n') {
            words++;
            wordLen = 0;
        }
        if(ch=='\n')
            lines++;
    }
    f.close();
        cout << "statysytyki do pliku o nazwie" << fileName << endl;
        cout << "ilosc slow: " << words << endl;
        cout << "ilosc linii: " << lines;
}

int linesInFile(string fileName) {
    ifstream inputFile(fileName);
    char ch;
    int lines = 1;
    while (inputFile) {
        inputFile.get(ch);
        if(ch=='\n')
            lines++;
    }
    inputFile.close();
    return lines;
}

int wordsInFile(string fileName) {
    ifstream inputFile(fileName);
    char ch;
    int wordCount = 0;
    while(inputFile) {
        inputFile.get(ch);
        if(ch==32)
            wordCount++;
    }
    inputFile.close();
    return wordCount;
}

string wordStats(string fileName) {
    string result;
    ifstream inputFile(fileName);
    char ch;
    int longestWordLength = -1, shortestWordLength = -1, tempWordLength = 0, sum = 0, amount = 0;
    while(inputFile) {
        inputFile.get(ch);
        ch = tolower(ch);
        //if(ch<97 || ch>122 ) {
        if(ch==32 || ch=='\n') {
            cout << endl << "word length: " << tempWordLength;  
            if(longestWordLength == -1 || tempWordLength > longestWordLength)
                longestWordLength = tempWordLength;
            if(shortestWordLength == -1 || tempWordLength < shortestWordLength)
                shortestWordLength = tempWordLength;
            sum += tempWordLength;
            amount++;
            tempWordLength = 0;
        }
        else
            tempWordLength++;  
    }
    inputFile.close();
    cout << endl <<  "amount of words: " << amount << endl;
    cout << "shortest word: " << shortestWordLength << " letters" << endl;
    cout << "longest word " << longestWordLength << " letters" << endl;
    cout << "average length " << (1.0*sum)/amount << " letters";
    cout << setprecision(3);
    result = "shortest word: " + to_string(shortestWordLength) + 
    "\nlongest word: " + to_string(longestWordLength) +
    "\naverage length: " + to_string((1.0*sum)/amount);

    return result;
}

void outputStats(string inputFile, string outputFile) {
    ofstream outStream(outputFile);
    outStream << "stats for file \"" << inputFile << "\": " << endl <<
        "lines: " << linesInFile(inputFile) << endl <<
        "words: " << wordsInFile(inputFile) << endl;
    outStream << wordStats(inputFile);
    outStream.close();
}

int main() {

    string fileName = "file1.txt";
    stats(fileName);
    cout << endl <<  "lines " << linesInFile(fileName) << endl;
    wordStats(fileName);

    outputStats(fileName, "stats.txt");

    return 0;
}