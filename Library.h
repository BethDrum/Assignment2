#ifndef LIBRARY
#define LIBRARY

#include "Member.h"
#include "Book.h"
#include "Library.h"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Library{
    private:
        vector<Member> membList;
        vector<Book> libBookList;

    public:
        void addMembList(string membID, string nam);
        void removeMembList(string membID);
        bool searchForMemb(string searchID);
        void addLibBook(string bID, string ti, string au, string gen, int pgC);
        void removeLibBook(string bookID);
        void dispAllMemb();
        void borrowBook(string bkID, string memID);
        void returnBook(string bkID, string memID);
        vector<string> split(string str);
        int readFromFile(string fileName);
        void searchForBook(string searchID);
};
#endif