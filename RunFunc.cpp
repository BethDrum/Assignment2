#include "RunFunc.h"

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;

//to add a new publication to the library
void RunFunc::runAddPub(){
    //get all values from user
    try{
        cout << "Add a book selected.\n--------------\n";
        cout << "Enter Title: " << endl;
        cin.ignore();
        getline(cin, ti);
        cout << "Enter Author: " << endl;
        getline(cin, au);
        cout << "Enter Genre: " << endl;
        getline(cin, gen);
        cout << "Enter Page Count: " << endl;
        cin >> pgC;
    }catch (exception e){
        cout << "There has been a incorrect value added. Please run again to retry" << endl;
    }
    //generate book ID - B then 3 random numbers
    do{
        srand(static_cast<unsigned>(time(nullptr)));
        num = rand() % 201;
        bID = "B"+to_string(num);
    //ensure ID dosent exist
    }while (!Lib.checkPubID(bID));

    //get type and finally add to the library for each one.
    do{
        cout << "Please enter B for book, M for magazine, J for journal or E for eBook." << endl;
        cin >> type;
    }while (type != "B" && type != "M" && type != "J" && type != "E");
    if (type == "B"){
        Lib.addLibBook(bID, ti, au, gen, pgC);
    }else if (type == "M"){
        cout << "Please enter the issue number:" << endl;
        cin >> extraMInfo;
        Lib.addLibMag(bID, ti, au, gen, pgC, extraMInfo);
    }else if (type == "J"){
        cout << "Please enter the volume:" <<endl;
        cin >> extraJInfo;
        Lib.addLibJour(bID, ti, au, gen, pgC, extraJInfo);
    }else if (type == "E"){
        cout << "Please enter the number of minutes to finish the book:" <<endl;
        cin >> extraEInfo;
        Lib.addLibEbook(bID, ti, au, gen, pgC, extraEInfo);
    }
}

//to add a new publication to the library with predefined values
void RunFunc::runAddPubValues(string ti, string au, string gen, int pgC){
    //generate book ID - B then 3 random numbers
    do{
        srand(static_cast<unsigned>(time(nullptr)));
        num = rand() % 201;
        bID = "B"+to_string(num);
    //ensure ID dosent exist
    }while (!Lib.checkPubID(bID));
    //add to library
    Lib.addLibBook(bID, ti, au, gen, pgC);
}

//to remove a publication
void RunFunc::runRemovePub(){
    do{
        cout << "Enter the Book ID of the book you wish to remove: " << endl;
        cin >> bID;
    }while (bID[0] != 'B');
    Lib.removeLibPub(bID);
}

//to run a search
void RunFunc::runSearch(){
    //ask user for values
    cout << "Please enter if you are searching for: \nT: Title \nA: Author \nG: Genre \nAV: Availiability \nID: Book ID" << endl;
    cin >> typeSearch;
    cout << "Please enter the search term: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, searchID);
    //run search
    Lib.searchForBook(searchID, typeSearch);
}

//run search with given values
void RunFunc::runSearchVal(string typeSearch, string searchID){
    Lib.searchForBook(searchID, typeSearch);
}

//to display all publications
void RunFunc::runDisplayP(){
    Lib.dispAllPub();
}

//to display all members
void RunFunc::runDisplayM(){
    Lib.dispAllMemb();
    cout << endl;
}

//to check if a member exists
bool RunFunc::checkMemb(string mID){
    return (Lib.checkMem(mID));
}

//to add a member
void RunFunc::runAddMember(){
    cout << "Please enter the member name: " << endl;
    cin >> name;
    //generate member ID
    srand(static_cast<unsigned>(time(nullptr)));
    num = rand() % 201;
    mID = "M"+to_string(num);
    //add to memberlist
    if (!Lib.checkMem(mID)){
        Lib.addMembList(mID, name);
    }
}

//to add a member with a known name
void RunFunc::runAddMemberValue(string nam){
    //generate member ID
    srand(static_cast<unsigned>(time(nullptr)));
    num = rand() % 201;
    mID = "M"+to_string(num);

    Lib.addMembList(mID, nam);
}

//to remove a member
void RunFunc::runRemoveMember(){
    //gather the member ID to delete
    do{
        cout << "Enter the ID of the member you wish to delete: " << endl;
        cin >> mID;
    }while(mID[0] != 'B');
    //delete the member
    if (!Lib.removeMembList(mID)){
        cout << "The member does not exist";
    }
}

//to read a new file in
void RunFunc::runReadFile(){ 
    //get both files from the user
    string bkFile = "";
    string mFile = "";
    cout << "Enter the book file to read: " << endl;
    cin.ignore();
    cin >> bkFile;
    cout << "Enter the member file to read: " << endl;
    cin.ignore();
    cin >> mFile;
    //run readFrom File
    Lib.readFromFile(bkFile, mFile);
}

//to read in a new file with given files
void RunFunc::runReadFileGotFile(string bkFile, string mFile){ 
    Lib.readFromFile(bkFile, mFile);
}

//save to file, asking user for files
void RunFunc::runSaveFile(){
    //get in files from user to save to
    string bkFile = "";
    string mFile = "";
    cout << "Enter the book file to save to: " << endl;
    cin >> bkFile;
    cout << "Enter the member file to save to: " << endl;
    cin >> mFile;
    //run save function
    Lib.saveToFile(bkFile, mFile);
}

//save to file with given files
void RunFunc::runSaveFileValues(string bkFile, string mFile){
    Lib.saveToFile(bkFile, mFile);
}

//to allow a user to borrow a publication
void RunFunc::runBorrow(string mID){
    do{
        cout << "Enter the ID of the book you wish to borrow: " << endl;
        cin >> bID;
    }while(bID[0] != 'B');

    if (Lib.borrowPub(bID, mID)){
        cout << "The book is now borrowed." << endl;
    }else{
        cout << "The book cannot be taken out at this time." << endl;
    }
}

//to allow a user to borrow a publication with a given bookID
void RunFunc::runBorrowKnown(string bID, string mID){
    if (Lib.borrowPub(bID, mID)){
        cout << "The book is now borrowed." << endl;
    }else{
        cout << "The book cannot be taken out at this time." << endl;
    }
}

//to allow a user to return a members borrowed publication
void RunFunc::runReturn(string bID, string mID){
    do{
        cout << "Enter the ID of the book you wish to return." << endl;
        cin >> bID;
    }while(bID[0] != 'B');

    Lib.returnPub(bID, mID);
}

//to allow the user to see all borrowed books for that member
void RunFunc::runViewBorrowed(string mID){
    Lib.viewBorrowed(mID);
}