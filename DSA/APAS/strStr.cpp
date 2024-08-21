#include <iostream>
#include <string>
using namespace std;

int strStr(string s, string needle) {

    int index, counter = 0;
    if (s.length() == 0) return 0;

    for (int i=0; i<s.length(); i++) {
        if (s[i] == needle[0]) {
            index = i;
            break;
        }
    }

    for (int i=index; i<needle.length()+index; i++) {
        if (s[i] != needle[counter]) {
            return -1;
        }

        counter++; 
    }

    return index;
}

int main() {
    string s1 = "Hello";
    string needle = "ll";



    int ans = strStr(s1, needle);
    
    cout<<"-----------"<<endl;
    cout<<"Ans: "<<ans<<endl;

    return 0;
}