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
template <class T>

class Library{
    private:
        vector<Member> membList;
        vector<Book> libBookList;

    public:
        void addMembList(int membID, string nam, int bkList);
        void removeMembList(int membID);
        void addLibBook(int bID, string ti, string au, string gen, int pgC, bool ava);
        void removeLibBook(int bookID);
        void searchForBook(T searchID);
        void dispAllMemb();
        void borrowBook(int bkID, int memID);
        void returnBook(int bkID, int memID);
        vector<string> split(string str);
        int readFromFile(string fileName);
};
#endif