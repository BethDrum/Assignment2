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
        vector<Member<BorrowedBk>> membList;
        vector<Publication*> readingList;

    public:
        void addMembList(string membID, string nam);
        bool removeMembList(string membID);
        bool searchForMemb(string searchID);

        void addLibBook(string pID, string ti, string au, string gen, int pgC);
        bool checkPubID(string bkID);
        void addLibJour(string pID, string ti, string au, string gen, int pgC, int vol);
        void addLibMag(string pID, string ti, string au, string gen, int pgC, int issueN);
        void addLibEbook(string pID, string ti, string au, string gen, int pgC, int mins);
        void removeLibPub(string pubID);

        void dispAllPub(); 
        void dispAllMemb();

        bool borrowPub(string pbID, string memID);
        void returnPub(string pbID, string memID);
        void viewBorrowed(string mID);

        vector<string> split(string str);
        bool readFromFile(string fileNameB, string filenameM);
        bool searchForBook(string searchID, string type);
        bool saveToFile(string bkFile, string mFile);
        double checkPenalty(time_t borrDate, string type);
        time_t getDate(); 
        int fuzzySearch(string check, string change);
        int LevenshteinFunc(const string& str1, const string& str2);
        bool wildcardS(string searchID, string pattern);
        bool checkMem(string mID);
        string removeSpaces(string str);
};
#endif