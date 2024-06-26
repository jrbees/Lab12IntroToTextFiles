#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void pressEnterToContinue();
bool readFromFile(string filename);

int main() {
    string datafile;
    cout << "Lab 12 Intro to Text Files!\n";
    cout << "Enter Filename: ";
    getline(cin, datafile);
    bool status = readFromFile(datafile);
    if (status) cout << "Success!\n";
    else        cout << "Failure. ;-(\n";

    pressEnterToContinue();
}

void pressEnterToContinue() {
    cout << "\nPress enter to continue... \n";
    cin.clear();
    while (cin.get() != '\n') continue;
}

bool readFromFile(string filename) {
    ifstream inFile;
    string word;
    int wordCount = 0;
    int charCount = 0;

    inFile.open(filename);
    if (inFile.fail()) {
        cout << "Read error - sorry\n";
        return false;
    }

    while (inFile >> word) {
        bool containsLetter = false;
        for (char c : word) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                charCount++; // Count only if it's an alphabetic character
                containsLetter = true;
            }
        }
        if (containsLetter) {
            wordCount++; // Only count words with at least one letter
        }
    }

    cout << "Word count: " << wordCount << endl;
    cout << "Character count: " << charCount << endl;

    inFile.close();
    return true;
}

