#include<iostream>
using namespace std;

int main() {
    int num;
    cin>>num;

    char ch='I';
    int rem=0;
                
    switch(ch) {
        
        case 'I':
            cout<<num / 100<<" 100 notes"<<endl;
            rem = num % 100;

        case 2:
            cout<<rem / 50<<" 50 notes"<<endl;
            rem = rem % 50;
        
        case 3:
            cout<<rem / 20<<" 20 notes"<<endl;
            rem = rem % 20;

        case 4:
            cout<<rem / 1<<" 1 notes"<<endl;
            break;

    }

}