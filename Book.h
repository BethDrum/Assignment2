#ifndef BOOK
#define BOOK

//#include "Member.h"
#include <string>
using namespace std;

class Book{
    private:
        int bookID;
        string title;
        string author;
        string genre;
        int pgCount;
        bool avai;

    public:
        int getBookID();
        void setBookID(int newBookID);
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
        Book(int bID, string ti, string au, string gen, int pgC, bool ava);
};

#endif