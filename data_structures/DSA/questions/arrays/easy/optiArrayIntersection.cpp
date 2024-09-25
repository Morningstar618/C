#include<iostream>
#include<vector>
using namespace std;

int main() {
    int size1=6;
    int tarr1[size1] = {1,2,2,2,3,4};
    
    int size2=4;
    int tarr2[size2] = {2,2,3,3};
    
    int i=0, j=0;
    vector<int> ans;

    while(i<size1 && j<size2) {
        if (tarr1[i]==tarr2[j]) {
            ans.push_back(tarr1[i]);
            i++;
            j++;
        } else if (tarr1[i] < tarr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (int x : ans) {
        cout<<x<<" ";
    }
}