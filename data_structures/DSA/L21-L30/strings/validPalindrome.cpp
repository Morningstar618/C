#include<iostream>
using namespace std;

bool valid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return 1;
    } else {
        return 0;
    }
}

char toLowercase(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 0 && ch <= 9)) {
        return ch;
    } else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string a) {
    int s = 0, e = a.length() - 1;

    while (s<=e) {
        if (a[s] != a[e]) {
            return 0;
        } else {
            s++; e--;
        }
    }
    return 1;
}

bool isPalindrome(string s) {
    //removing irrelevant characters
    string temp = "";
    for (int i=0; i<s.length(); i++) {
        if (valid(s[i])) {
            temp.push_back(s[i]);
        }
    }

    //Convert into Lowercase
    for (int i=0; i<temp.length(); i++) {
        temp[i] = toLowercase(temp[i]);
    }

    //Check Palindrome
    return checkPalindrome(temp);
}

int main() {
    string s = "A man, a plan, a canal: Panama";

    cout<<isPalindrome(s)<<endl;
    return 0;
}