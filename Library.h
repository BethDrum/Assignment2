#ifndef LIBRARY
#define LIBRARY

#include "Member.h"
#include "Publication.h"
#include "Library.h"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;

class Library{
    private:
        vector<Member> membList;
        vector<Publication> readingList;

    public:
        bool addMembList(string membID, string nam);
        bool removeMembList(string membID);
        bool searchForMemb(string searchID);

        bool addLibBook(string pID, string ti, string au, string gen, int pgC);
        bool addLibJour(string pID, string ti, string au, string gen, int pgC, int vol);
        bool addLibMag(string pID, string ti, string au, string gen, int pgC, int issueN);
        bool removeLibPub(string pubID);

        void dispAllPub(); //ERROR
        void dispAllMemb();

        bool borrowPub(string pbID, string memID);
        bool returnPub(string pbID, string memID);

        vector<string> split(string str);
        int readFromFile(string fileName);
        void searchForBook(string searchID);
        bool saveToFile();
        void checkReturn(int outYr, int outMon, int outDay); //MATHS AND NEED TO KNOW USEAGE TO FIMISH
        void multiSearch(string data); //NEEDS TEMPALTE SO CAN SEARCH AVAILIABOLITY TOO
};
#endif