#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int,string> m;

    m[1] = "Ayush";
    m[13] = "Hacker";
    m[2] = "Joshi";

    m.insert({5, "Karna"});

    cout<<"before erase"<<endl;
    for (auto i:m) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<endl;
    cout<<"finding 13 -> "<<m.count(13)<<endl;

    m.erase(13);

    cout<<endl;
    cout<<"after erase"<<endl;
    for (auto i:m) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(5);
    cout<<endl;
    for (auto i=it; i!=m.end(); i++) {
        cout<<(*i).first<<endl;
    }

    return 0;
}