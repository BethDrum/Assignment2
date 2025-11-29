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
        bool avai;

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
        bool getAvai();
        void setAvail(bool newAvai);
        Book(string bID, string ti, string au, string gen, int pgC);
        Book(string bID, string ti, string au, string gen, int pgC, bool ava);
};

#endif