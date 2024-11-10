#include<iostream>
using namespace std;

int main() {
    int n, row=1;
    cin >> n;

    char ch='A';

    while(row<=n) {
        int col=1;

        while(col<=n) {
            cout << ch << " ";
            col++;
            ch++;
        }
        cout << endl;
        row++;
    }
}