#ifndef LIBRARY
#define LIBRARY

#include "Member.h"
#include "Publication.h"

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
        vector<Publication*> readingList;

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
        void viewBorrowed(string mID);

        vector<string> split(string str);
        int readFromFile(string fileNameB, string filenameM);
        void searchForBook(string searchID, string type);
        bool saveToFile();
        double checkPenalty(time_t borrDate, string type);
        time_t getDate(); //MATHS AND NEED TO KNOW USEAGE TO FIMISH
        int fuzzySearch(string check, string change);
        int LevenshteinFunc(string str1, string str2, int m, int n);
        bool wildcardS(string searchID, string pattern);
};
#endif