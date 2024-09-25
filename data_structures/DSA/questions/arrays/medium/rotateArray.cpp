#include<iostream>
#include<vector>
using namespace std;

vector<int> rotate(vector<int> v, int k) {
    vector<int> temp(v.size());

    for (int i=0; i<v.size(); i++) {
        temp[(i+k)%v.size()] = v[i];
    }

    // copy temp into v vector
    v = temp;
    return v;
}

void printVector(vector<int> v) {
    for (int i:v) {
        cout<<i<<" ";
    } cout<<endl;
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7};
    v = rotate(v, 3);
    printVector(v);

    return 0;
}
