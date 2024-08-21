#include<iostream>
#include<vector>
using namespace std;

vector<int> moveZeroes(vector<int> v) {
    int nonZero = 0;

    // shift all non zeroes values to the left

    for (int j=0; j<v.size(); j++) {
        if (v[j] != 0) {
            swap(v[j], v[nonZero]);
            nonZero++;
        }
    }

    return v;
}

void printVector(vector<int> v) {
    for (int i:v) {
        cout<<i<<" ";
    } cout<<endl;
}

int main() {
    vector<int> v = {0,1,0,3,12};
    v = moveZeroes(v);
    printVector(v);

    return 0;
}