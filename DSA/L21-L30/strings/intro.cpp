#include<iostream>
using namespace std;

char toLowerCase(char ch) {
    if (ch>='a' && ch<='z') {
        return ch;
    } else {
        char temp = ch - 'A' + 'a';         //IMPORTANT
        return temp;
    }
}

bool checkPalindrome(char a[], int n) {
    // checks if a string is a palindrome or not
    // skips special characters, only alpha-numeric characters are counted

    int s=0, e=n-1;

    while(s<=e) {
                                            // ############### IMPORTANT
        if (!(48<=a[s] && a[s]<=57) && !(65<=a[s] && a[s]<=90) && !(97<=a[s] && a[s]<=122)) {
            s++;                // SKIP character
        } else if (!(48<=a[e] && a[e]<=57) && !(65<=a[e] && a[e]<=90) && !(97<=a[e] && a[e]<=122)) {
            e--;
        } else if (toLowerCase(a[s]) != toLowerCase(a[e])) {
            return 0;
        } else {
            s++; e--;
        }
    }
    return 1;
}

void reverse(char name[], int n) {
    int s=0, e=n-1;
    while(s<e) {
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[]) {
    int count = 0;
    for (int i=0; name[i]!='\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    char name[20];
    cout<<"Enter your name: ";
    cin>>name;

    int len = getLength(name);

    cout<<"Your name is "<<name<<endl;
    cout<<" Length: "<<len<<endl;

    reverse(name, len);
    cout<<endl<<"Reversing name: "<<name<<endl;

    cout<<" Palindrome or Not: "<<checkPalindrome(name, len)<<endl;

    cout<<endl;
    cout<<"Character is: "<<toLowerCase('b')<<endl;
    cout<<"Character is: "<<toLowerCase('B')<<endl;
}