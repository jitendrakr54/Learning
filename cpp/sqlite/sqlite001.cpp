#include <iostream>
#include <sqlite3.h>
#include <string.h>

int createDB(std::string db);
int createTable(std::string db);
int InsertRecord(std::string db);

int main() {
    std::cout<<"Welcome to SQLite with C++!\n";
    std::string db{"test.db"};
    // createDB(db);
    // createTable(db);
    InsertRecord(db);
    // closeDB(db);
    return 0;
}

int createDB(std::string db) {
    sqlite3* DB;
    sqlite3_open(db.c_str(), &DB);
    return 0;
}

int createTable(std::string db) {
    sqlite3* DB;
    std::string query = "CREATE TABLE EMPLOYEE("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NAME TEXT NOT NULL, "
        "LANAME TEXT NOT NULL, "
        "AGE INT NOT NULL, "
        "ADDRESS TEXT NOT NULL);";

    try {
        int exit = 0;
        exit = sqlite3_open(db.c_str(), &DB);
        char *messageError;
        exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &messageError);
        if(exit != SQLITE_OK) {
            std::cerr<<"Error creating table!"<<messageError<<"\n";
            // sqlite3_free(messageError);
        } else {
            std::cout<<"Table created successfully!\n";
            sqlite3_close(DB);
        }
    } catch(std::exception &e) {
        std::cerr<<e.what()<<"\n";
    }
    return 0;
}

int InsertRecord(std::string db) {
    sqlite3* DB;
    std::string query = "INSERT into EMPLOYEE VALUES(581, 'Jitendra', 'KUMAR', 27, 'BTM');";

    try {
        int exit = 0;
        exit = sqlite3_open(db.c_str(), &DB);
        char *messageError;
        exit = sqlite3_exec(DB, query.c_str(), NULL, 0, &messageError);
        if(exit != SQLITE_OK) {
            std::cerr<<"Error inerting into table!"<<messageError<<"\n";
            // sqlite3_free(messageError);
        } else {
            std::cout<<"Data inserted successfully!\n";
            sqlite3_close(DB);
        }
    } catch(std::exception &e) {
        std::cerr<<e.what()<<"\n";
    }
    return 0;
}

// int closeDB(std::string db) {
//     return 0;
// }