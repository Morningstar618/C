#include "include/database.h"

void Database::write(vector<vector <string>> mainList) {
    
    ofstream db;
    db.open("db/lists.sl");

    if (db.is_open()) {
        // for (int list_index=0; list_index<(int)mainList.size(); list_index++) {
        for (int user_index=0; user_index<(int)mainList.size(); user_index++) {
            for (int list_index=0; list_index<(int)mainList[user_index].size(); list_index++) {
                if (list_index==0) {
                    db<<"#"<<mainList[user_index][list_index]<<endl;
                } else {
                    db<<mainList[user_index][list_index]<<endl;
                }
            }
            db<<"%"<<endl;
        }
    } else {
        cout<<"Cannot open file for writing.";
    }

    db.close();
}

vector<vector <string>> Database::read() {
    string line;
    ifstream db;
    db.open("db/lists.sl");

    vector<string> userList;

    if (db.is_open()) {
        while (getline(db, line, '\n')) {
            if (line.front()=='#') {
                cout<<"Found a Hashtag: "<<line<<endl;
                line.erase(line.begin());
                userList.push_back(line);
            } else if (line.front()=='%') {
                cout<<"Found a Percentage: "<<line<<endl;
                mainList.push_back(userList);
                userList.clear();
            } else {
                cout<<"Found an Item: "<<line<<endl;
                userList.push_back(line);
            }
        }
    } else {
        cout<<"Cannot open file for reading.\n";
    }

    db.close();
    return mainList;
}