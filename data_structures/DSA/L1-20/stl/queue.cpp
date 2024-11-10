#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<string> q;

    q.push("Hacker");
    q.push("Ayush");
    q.push("Joshi");

    cout<<"Size before pop -> "<<q.size()<<endl;

    cout<<"First Element ->"<<q.front()<<endl;
    q.pop();
    cout<<"First Element ->"<<q.front()<<endl;    

    cout<<"Size after pop -> "<<q.size()<<endl;

    return 0;
}