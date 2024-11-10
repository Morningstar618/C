#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v;
    vector<int> a(5,1);
    vector<int> last(a);

    cout<<"Print vector Last"<<endl;
    for (int i:last) {
        cout<<i<<" ";
    }cout<<endl<<endl;

    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"Capacity-> "<<v.capacity()<<endl;
    v.push_back(4);
    cout<<"Capacity-> "<<v.capacity()<<endl;    
    v.push_back(5);
    cout<<"Capacity-> "<<v.capacity()<<endl;

    cout<<endl;
    cout<<"Size-> "<<v.size()<<endl;
    cout << "Element at 2nd Index-> "<<v.at(2)<<endl;    
    cout<<"First Element-> "<<v.front()<<endl;
    cout<<"Last Element-> "<<v.back()<<endl;

    cout<<endl;
    cout<<"Before Pop"<<endl;
    for (int i:v) {
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();

    cout<<"After Pop"<<endl;
    for (int i:v) {
        cout<<i<<" ";
    }cout<<endl;


    v.pop_back();
    cout<<"Another pop"<<endl;
    for (int i:v) {
        cout<<i<<" ";
    }cout<<endl;
    cout<<"Capacity-> "<<v.capacity()<<endl;

    cout<<"Before clear Size-> "<<v.size()<<endl;
    v.clear();
    cout<<"After clear Size-> "<<v.size()<<endl;

    return 0;
}