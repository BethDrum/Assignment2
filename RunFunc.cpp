#include "RunFunc.h"

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
using namespace std;

    
void RunFunc::runAddPub(){
    //get all values from user
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

    //generate book ID - B then 3 random numbers?
    srand(static_cast<unsigned>(time(nullptr)));
    num = rand() % 201;
    bID = "B"+to_string(num);
    cout << bID << endl;
    //get type
    //cout << "Please enter B for book, M for magazine or J for journal." << endl;
    //cin >> type;
    do{
        cout << "Incorrect entered value, \nPlease enter B for book, M for magazine or J for journal." << endl;
        cin >> type;
    }while (type != "B" && type != "M" && type != "J");

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
    }
}

void RunFunc::runRemovePub(){
    cout << "Enter the Book ID of the book you wish to remove: " << endl;
    cin >> bID;
    Lib.removeLibPub(bID);
}

void RunFunc::runSearch(){
    cout << "Please enter if you are searching for: \nT: Title \nA: Author \nG: Genre \nAV: Availiability \nID: Book ID" << endl;
    cin >> typeSearch;
    cout << "Please enter the search term: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, searchID);
    cout << searchID << endl;
    Lib.searchForBook(searchID, typeSearch);
}

void RunFunc::runDisplayP(){
    Lib.dispAllPub();
}

void RunFunc::runDisplayM(){
    Lib.dispAllMemb();
    cout << endl;
}

void RunFunc::runAddMember(){
    cout << "Please enter the member name: " << endl;
    cin >> name;
    //generate member ID
    srand(static_cast<unsigned>(time(nullptr)));
    num = rand() % 201;
    mID = "M"+to_string(num);

    Lib.addMembList(mID, name);//ID and name
}

void RunFunc::runRemoveMember(){
    cout << "Enter the ID of the member you wish to delete: " << endl;
    cin >> mID;
    if (!Lib.removeMembList(mID)){
        cout << "The member does not exist";
    }
}

void RunFunc::runReadFile(){ //ADD THE USER ENTERING THEIR OWN FILE ---------------------------------------
    Lib.readFromFile("books.txt", "members.txt");
}

void RunFunc::runSaveFile(){
    Lib.saveToFile();
}

void RunFunc::runBorrow(){
    cout << "Enter the ID of the book you wish to borrow: " << endl;
    cin >> bID;
    if (Lib.borrowPub(bID, mID)){
        cout << "The book is now borrowed." << endl;
    }else{
        cout << "Error occured: Book not availiable" << endl;
    }
}

void RunFunc::runReturn(){
    cout << "Enter the ID of the book you wish to return." << endl;
    cin >> bID;
    Lib.returnPub(bID, mID);
}
 
void RunFunc::runViewBorrowed(){
    Lib.viewBorrowed(mID);
}