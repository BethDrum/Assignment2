#ifndef BOOK
#define BOOK

#include <string>
#include <iostream>
using namespace std;

class Publication{
    protected:
        string pubID;
        string title;
        string author;
        string genre;
        int pgCount;
        int avai;
        string type;

    public:
        string getPubID();
        void setPubID(string newBookID);
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
        string getType();
        virtual void viewInfo();
};


class Book : public Publication{
    public:
        Book(string bID, string ti, string au, string gen, int pgC);
        Book(string bID, string ti, string au, string gen, int pgC, int ava);
        void viewInfo();
};

class Magazine : public Publication{
    private:
        int issueNum;
    public:
        int getIssueN();
        void setIssueN(int newIssueN);
        Magazine(string pID, string ti, string au, string gen, int pgC, int issueN);
        Magazine(string pID, string ti, string au, string gen, int pgC, int issueN, int ava);
        void viewInfo();
};

class Journal : public Publication{
    private:
        int volume;
    public:
        int getVol();
        void setVol(int newVol);
        Journal(string pID, string ti, string au, string gen, int pgC, int vol);
        Journal(string pID, string ti, string au, string gen, int pgC, int vol, int ava);
        void viewInfo();
};

#endif