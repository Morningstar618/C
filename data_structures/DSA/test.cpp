#include<iostream>
using namespace std;

int main() {
    string s = "daabcbaabcbc";
    string part = "aab";
    cout<<s.erase(s.find("aab"), part.length())<<endl;
}
