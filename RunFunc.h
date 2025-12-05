#ifndef RUNF
#define RUNF

#include "Library.h"

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class RunFunc{
    private:
        //initialise all many needed fields
        Library Lib;
        int choice1;
        int choice2;
        int choice3;
        bool doneAll = false;
        bool doneMem = false;
        bool doneAdm = false;
        string bID = "";
        string ti = "";
        string au = "";
        string gen = "";
        int pgC = 0;
        int num = 0;
        string name = "";
        string mID = "";
        string type = "";
        int extraJInfo = 0;
        int extraMInfo = 0;
        int extraEInfo = 0;
        string typeSearch = "";
        string searchID = "";

    public:
        void runAddPub();
        void runAddPubValues(string ti, string au, string gen, int pgC);
        void runRemovePub();
        void runSearch();
        void runSearchVal(string typeSearch, string searchID);
        void runDisplayP();
        void runDisplayM();
        void runAddMember();
        void runAddMemberValue(string nam);
        void runRemoveMember();
        void runReadFile();
        void runReadFileGotFile(string bkFile, string mFile);
        void runSaveFile();
        void runSaveFileValues(string bkFile, string mFile);
        void runBorrow(string mID);
        void runBorrowKnown(string bID, string mID);
        void runReturn(string bID, string mID);
        void runViewBorrowed(string mID);
        bool checkMemb(string mID);
};

#endif