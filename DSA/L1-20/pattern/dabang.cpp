#include<iostream>
using namespace std;

int main() {
    int n, row=1;
    cin>>n;

    while(row<=n) {
        //print 1st num
        int col = 1;
        int num1 = n - row + 1;

        while(col<=num1) {
            cout << col;
            col++;
        }
        
        //print 1st star
        int star1 = row - 1;
        while(star1) {
            cout<<"*";
            star1--;
        }

        //print 2nd star
        int star2 = row - 1;
        while(star2) {
            cout<<"*";
            star2--;
        }

        //print 2nd num
        col--;
        while(col>=1) {
            cout<<col;
            col--;
        }

        cout<<endl;
        row++;

    }
}