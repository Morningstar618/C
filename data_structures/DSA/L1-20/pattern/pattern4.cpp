#include<iostream>
using namespace std;

// Commented out is way 2
int main() {
    int n, row=1;
    cin >> n;

    // char ch='A';

    while(row<=n) {
        int col=1;

        while(col<=n) {
            cout << (char) ('A' + row + col - 2) << " ";
            col++;
            // ch++;
        }
        cout << endl;
        row++;
        // ch -= 2;
    }
}