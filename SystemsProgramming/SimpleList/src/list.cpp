#include "include/list.h"

void List::print_menu() {
    int choice;

    cout<<"*****************\n";
    cout<<" 1 - Print List.\n";
    cout<<" 2 - Add to List.\n";
    cout<<" 3 - Delete from List.\n";
    cout<<" 4 - Save List.\n";
    cout<<" 5 - Ouit.\n";
    
    cout<<" Enter your choice and press return: ";
    cin>>choice;

    if (choice==5) {
        return;
    } else if (choice==4) {
        save_list();
    } else if (choice==2) {
        add_item();
    } else if (choice==3) {
        delete_item();
    } else if (choice==1) {
        print_list();
    }
    else {
        cout<<"Sorry choice not implemented yet\n";
    }
}

void List::add_item() {
    cout<<"\n\n\n\n\n";
    cout<<"*** ADD ITEM ***\n";

    cout<<"Type in an item and press enter: ";
    string item;
    cin>>item;

    list.push_back(item);

    cout<<"\nSuccessfully added an item to the list \n\n\n";
    cin.clear();

    print_menu();
}

void List::delete_item() {
    cout<<"*** DELETE ITEM ***\n";
    cout<<"Select an item index number to delete\n";
    if (list.size()) {
        for (int i=0; i<(int)list.size(); i++) {
            cout<<i<<": "<<list[i]<<endl;
            }
        int choiceNum;
        cin>>choiceNum;
        list.erase(list.begin()+choiceNum);
    } else {
        cout<<"No items to delete.\n";
    }

    print_menu();
}

void List::print_list() {
    cout<<"\n\n\n\n\n";
    cout<<"*** PRINTING LIST ***"<<endl;
    for (int list_index=0; list_index<(int)list.size(); list_index++) {
        cout<<" * "<<list[list_index]<<endl;
    }

    cout<<"M - Menu \n";
    char choice;
    cin>>choice;

    if (choice=='M'||choice=='m') {
        print_menu();
    } else {
        cout<<"Invalid Choice. Quitting..\n";
    }
}

bool List::find_userList() {
    bool userFound=false;
    
    cout<<"\n\n\n\n\n";
    cout<<"*** Welcome "<<name<<" ***"<<endl;

    for (int user_index=0; user_index<(int)mainList.size(); user_index++) {
        cout<<mainList[user_index][0]<<endl;
        if (mainList[user_index][0]==name) {
            cout<<"User has been found: "<<mainList[user_index][0]<<endl;
            list = mainList[user_index];
            currentUserIndex = user_index;
            userFound=true;
            break;
        }
    }

    if (userFound==false) {
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = (int)mainList.size()-1;
    }

    return userFound;
}

void List::save_list() {
    cout<<"Saving the list..."<<endl;
    mainList[currentUserIndex] = list;
    print_menu();
}