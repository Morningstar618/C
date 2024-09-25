#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char>& chars) {
    int i=0, ansIndex=0, n=chars.size();

    while (i<n) {
        int j=i+1;
        while (j<n && chars[i]==chars[j]) {
            j++;
        }
        //yaha kag aaoge
        //ya toh vector poora traverse krdia
        //ya fir New/Diff character encounter kia

        //old character store karlo
        chars[ansIndex++] = chars[i];

        int count = j-1;

        if (count>1) {
            //converting counting into single digit and saving in answer
            string cnt = to_string(count);
            for (char ch: cnt) {
                chars[ansIndex++] = ch;
            }
        }
        i=j;
    }
    return ansIndex;
}

int main() {
    vector<char> carr = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};

    cout<<"compressed array size is: "<<compress(carr)<<endl;
    for (char ch: carr) {
        cout<<ch<<" ";
    }cout<<endl;

    return 0;
}