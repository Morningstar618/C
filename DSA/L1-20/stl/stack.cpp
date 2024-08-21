#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<string> s;

    s.push("Ayush");
    s.push("Joshi");
    s.push("Hacker");

    cout<<"TOP -> "<<s.top()<<endl;
    
    s.pop();
    cout<<"Top -> "<<s.top()<<endl;

    cout<<"Size of stack ->"<<s.size()<<endl;

    cout<<"Empty or not ->"<<s.empty()<<endl;

    return 0;
}
