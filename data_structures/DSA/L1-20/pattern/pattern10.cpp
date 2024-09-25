#include<iostream>
using namespace std;

int main() {
    int n, row=1;
    cin>>n;

    while(row<=n) {
        int col=4;

        while(col>=row) {
            cout<<"*";
            col--;
        }
        cout<<endl;
        row++;
    }
}