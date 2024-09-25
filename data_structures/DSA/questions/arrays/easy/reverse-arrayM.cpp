#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> x, int M) {
    int s = M + 1, e = x.size() - 1;

    while(s<=e) {
        swap(x[s], x[e]);
        s++;
        e--;
    }

    return x;
}

void printArray(vector<int> x) {
    for (int i=0; i<x.size(); i++) {
        cout<<x[i]<<" ";
    } cout<<endl;
}

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    vector<int> ans = reverse(v,1);

    cout<<"Printing reversed Array: ";
    printArray(ans);
    cout<<endl;
}