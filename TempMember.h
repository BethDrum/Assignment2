#ifndef TEMPMEMBER
#define TEMPMEMBER

#include "TempMember.tpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Base{
    public:
        virtual void f() = 0;
};

template <class T>
class TempMember:public Base{
    private:
        vector<T> bookList;
    public:
        vector<T> getAllBooks();
        bool addPub(T pbID);
        void viewBooks();
        bool removePub(T pubID);

        void f() override{}

};

#endif
