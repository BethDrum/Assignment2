#ifndef MEMBER
#define MEMBER

#include "Publication.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//template <typename T>
class Member{
    private: 
        string memberID;
        string name;
        vector<string> bookList;
        time_t dateBorrowed;
        vector<string> reserveList;

    public:
        string getMembID();
        void setMembID(string newMemID);
        string getName();
        void setName(string newName);
        //void addBook(Book bk);
        bool removePub(string pbID);
        bool addRes(string pID);
        bool checkRes(string pID);
        bool removeRes(string pbID);
        Member(string membID, string nam);
        void viewBooks();
        void viewMemb();
        vector<string> getAllBooks();
        void setDateB(time_t date);
        time_t getDateB();
        
        //template <typename T>
        bool addPub(string pbID);
};

#endif