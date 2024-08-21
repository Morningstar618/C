#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> v) {
    int count = 0;
    int n = v.size();

    for (int i=1; i<n; i++) {
        if (v[i-1] > v[i]) {
            count++;
        }

        if (v[n-1] > v[0]) {
            count++;
        }
    }

    return count<=1;
}

int main() {
    vector<int> v = {3,4,5,1,2};
    cout<<check(v)<<endl;

    return 0;
}