#ifndef MEMBER
#define MEMBER

#include "Book.h"
#include <string>
#include <vector>
using namespace std;

class Member{
    private: 
        int memberID;
        string name;
        vector<Book> bookList;

    public:
        int getMembID();
        void setMembID(int newMemID);
        string getName();
        void setName(string newName);
        void addBookNew(int bID, string ti, string au, string gen, int pgC, bool ava);
        void addBook(Book bk);
        void removeBook(Book book);
        Member(int membID, string nam);
};

#endif