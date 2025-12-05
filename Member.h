#ifndef MEMBER
#define MEMBER

//#include "Publication.h"
#include "TempMember.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Member{
    private: 
        string memberID;
        string name;
        time_t dateBorrowed;
        vector<string> reserveList;

    public:
        TempMember<BorrowedBk> readingList;
        string getMembID();
        void setMembID(string newMemID);
        string getName();
        void setName(string newName);
        bool addRes(string pID);
        bool checkRes(string pID);
        bool removeRes(string pbID);
        Member(string membID, string nam);
        void viewMemb();
        void setDateB(time_t date);
        time_t getDateB();

        void borrowBook(T pbID);
        void returnBook(T pbID);
};

template <typename T>
void Member<T>::borrowBook(T pbID){
    readingList.addPub(pbID);
}

template <typename T>
void Member<T>::returnBook(T bkID){
    readingList.removePub(bkID);
}

#include "Member.tpp"
#endif