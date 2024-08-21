#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    vector<int> v = {1, 3, 6, 7};

    // v.push_back(1);
    // v.push_back(3);
    // v.push_back(6);
    // v.push_back(7);

    cout<<"Finding 6 -> "<<binary_search(v.begin(), v.end(), 6)<<endl;

    cout<<"lower bound -> "<<lower_bound(v.begin(), v.end(), 6) - v.begin()<<endl;
    cout<<"upper bound -> "<<upper_bound(v.begin(), v.end(), 6) - v.begin()<<endl;

    int a = 3;
    int b = 5;

    cout<<"Max -> "<<max(a,b)<<endl;
    cout<<"Min -> "<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a -> "<<a<<" b -> "<<b<<endl;

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout<<"reversed string -> "<<abcd<<endl;

    rotate(v.begin(), v.begin()+1, v.end());
    cout<<"after rotate -> ";
    for (int i:v) {
        cout<<i<<" ";
    } cout<<endl;

    sort(v.begin(), v.end());
    cout<<"after sorting -> ";
    for (int i:v) {
        cout<<i<<" ";
    } cout<<endl;

    return 0;
}