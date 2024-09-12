#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int N = 5000;

// Function to read records from "babyname.txt" and populate the arrays
int makeNameRecord(string state[], string gender[], int year[], string name[], int count[]) {
    ifstream infile("babyname.txt");
    if (!infile) {
        cerr << "Error opening file." << endl;
        return -1; // Return -1 to indicate an error
    }

    int i = 0;
    // Read data from the file and fill the arrays
    while (infile >> state[i] >> gender[i] >> year[i] >> name[i] >> count[i]) {
        i++;
        if (i >= N) break; // Ensure we do not exceed the array bounds
    }
    infile.close();
    return i; // Return the number of records read
}

// Function to print all records
void printoutallrecords(int cnt, string state[], string gender[], int year[], string name[], int count[]) {
    for (int i = 0; i < cnt; i++) {
        printoutcontents(state[i], gender[i], year[i], name[i], count[i]);
    }
    cout << "Total lines: " << cnt << endl;
}

// Function to find and count names starting with a given letter in a specific state
int findNames(int cnt, string state[], string gender[], int year[], string name[], int count[], char starting, string stname) {
    int matchCount = 0;
    for (int i = 0; i < cnt; i++) {
        if (state[i] == stname && !name[i].empty() && name[i][0] == starting) {
            matchCount++;
        }
    }
    return matchCount;
}

// Function to print the contents of a single record
void printoutcontents(string statename, string sex, int year, string name, int count) {
    cout << setw(5) << statename << "\t";
    cout << setw(3) << sex << "\t";
    cout << setw(5) << year << "\t";
    cout << setw(10) << name << "\t\t";
    cout << setw(5) << count << endl;
}

#endif // MAIN_HPP