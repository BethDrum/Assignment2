#ifndef MEMBER
#define MEMBER

#include "Book.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Member{
    private: 
        string memberID;
        string name;
        vector<Book> bookList;

    public:
        string getMembID();
        void setMembID(string newMemID);
        string getName();
        void setName(string newName);
        void addBook(string bID, string ti, string au, string gen, int pgC);
        //void addBook(Book bk);
        //void removeBook(int place);
        Member(string membID, string nam);
        void allBooks();
};

#endif