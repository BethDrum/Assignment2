#ifndef TEMPMEMBER
#define TEMPMEMBER

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Base{
    public:
        virtual void f() = 0;
};

struct BorrowedBk{
    string bookID;
    time_t date;
};

template <class T>
class TempMember:public Base{
    private:
        vector<T> bookList;
    public:
        vector<T> getAllBooks();
        bool addPub(const T& bk);
        void viewBooks();
        bool removePub(string pubID);

        void f() override{}

};

#include "TempMember.tpp"
#endif
