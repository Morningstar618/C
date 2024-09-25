#include<iostream>
using namespace std;

void printArray(int arr[], int size) {

    cout<<" printing the array "<<endl;
    //print the array
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }  
    cout<<" printing DONE"<<endl<<endl; 
}

int main() {

    //declare
    int number[15];

    //accessing an array
    cout<<"Value at 14 index "<<number[14]<<endl;

    // cout<<"Value at 20 index"<<number[20]<<endl;

    //initialising an array
    int second[3] = {5, 7, 11};
    //accessing an element
    cout<<"Value at 2 index "<<second[2]<<endl<<endl;


    int third[15] = {2, 7};
    int n=15;
    // printArray(third, n);

    int thirdSize = sizeof(third)/sizeof(int);
    cout<<" Size of Third is "<<thirdSize<<endl;


    //initializing all locations with zero
    int fourth[10] = {0};
    n=10;
    // printArray(fourth, n);


    //initializing all locations with ones [not possible with below line]
    int fifth[10] = {1};
    n=10;
    // printArray(fifth, n);

    int fifthSize = sizeof(fifth)/sizeof(int);
    cout<<" Size of Fifth is "<<fifthSize<<endl;



// ########### CHARACTER ARRAYS ###############
    char ch[5] = {'a', 'b', 'c', 'r', 'p'};
    
    cout<<" printing the array "<<endl;
    //print the array
    for (int i=0; i<5; i++) {
        cout<<ch[i]<<" ";
    }  
    cout<<" printing DONE"<<endl<<endl;
    


    cout<<endl<<endl<<"Everything is fine"<<endl<<endl;

    return 0;
}