#include<iostream>
using namespace std;

int main() {
    int n, row=1;
    cin >> n;

    while(row<=n) {
        int col = 1;

        while(col<=n) {
            cout << (char) ('A' + col - 1);
            col++;
        }
        cout << endl;
        row++;
    }
}