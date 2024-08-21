#include<iostream>
using namespace std;

int main() {
    int size=7, num=12;
    int tarr[size]={1,2,3,4,5,6,7};

    for (int i=0; i<size/2; i++) {
        for (int j=1; j<size; j++) {
            for (int k=2; k<size; k++) {
                if (tarr[i]+tarr[j]+tarr[k]==num && k>j && i!=j && j!=k) {
                    cout<<"Triplet: "<<tarr[i]<<" "<<tarr[j]<<" "<<tarr[k]<<endl;
                }
            }
        }
    }
} 