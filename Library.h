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
        vector<Member<string>> membList;
        vector<Publication*> readingList;

    public:
        void addMembList(string membID, string nam);
        bool removeMembList(string membID);
        bool searchForMemb(string searchID);

        void addLibBook(string pID, string ti, string au, string gen, int pgC);
        void addLibJour(string pID, string ti, string au, string gen, int pgC, int vol);
        void addLibMag(string pID, string ti, string au, string gen, int pgC, int issueN);
        void removeLibPub(string pubID);

        void dispAllPub(); //ERROR
        void dispAllMemb();

        bool borrowPub(string pbID, string memID);
        void returnPub(string pbID, string memID);
        void viewBorrowed(string mID);

        vector<string> split(string str);
        bool readFromFile(string fileNameB, string filenameM);
        bool searchForBook(string searchID, string type);
        bool saveToFile();
        double checkPenalty(time_t borrDate, string type);
        time_t getDate(); //MATHS AND NEED TO KNOW USEAGE TO FIMISH
        int fuzzySearch(string check, string change);
        int LevenshteinFunc(string str1, string str2, int m, int n);
        bool wildcardS(string searchID, string pattern);
};
#endif