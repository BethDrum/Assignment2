#ifndef BOOK
#define BOOK

//#include "Member.h"
#include <string>
using namespace std;

class Book{
    private:
        string bookID;
        string title;
        string author;
        string genre;
        int pgCount;
        int avai;

    public:
        string getBookID();
        void setBookID(string newBookID);
        string getTitle();
        void setTitle(string newTitle);
        string getAuthor();
        void setAuthor(string newAuthor);
        string getGenre();
        void setGenre(string newGenre);
        int getPgCount();
        void setPgCount(int newPgCount);
        int getAvai();
        void setAvail(int newAvai);
        Book(string bID, string ti, string au, string gen, int pgC);
        Book(string bID, string ti, string au, string gen, int pgC, int ava);
};

#endif