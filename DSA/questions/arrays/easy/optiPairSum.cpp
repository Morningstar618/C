#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Lecture 10 CodeStudio PairSum Solution
int main() {
    int size=5, num=5;
    int tarr[size]={1,2,3,4,5};

    vector< vector<int> > ans;

    for (int i=0; i<size; i++) {
        for (int j=i+1; j<size; j++) {
            if (tarr[i]+tarr[j]==num) {
                vector<int> temp;
                temp.push_back(min(tarr[i], tarr[j]));
                temp.push_back(max(tarr[i], tarr[j]));
                ans.push_back(temp);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}