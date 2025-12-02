#include "Library.h"

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    Library Lib;
    //Lib.readFromFile("books.txt");
    int choice1;
    int choice2;
    int choice3;
    bool doneAll = false;
    bool doneMem = false;
    bool doneAdm = false;

    //general testing - final has a memeber log & admin - admin does all the add/remove from library stuff, member can borrow books




    //menu for testing/running
    while (doneAll == false){
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

        cout << "Please enter if you wish to access the options for: \n1. Admins \n2. Members" << endl;
        cin >> choice1;
        //switch for admin or member
        switch(choice1){
            case 1:
                cout << "You have selected Admin options.\n--------------\n";
                while (doneAdm == false){
                    cout << "Enter a number to make you selection, your choices are: \n1. Add a book to the library. \n2. Remove a book from the Library. \n3. Search for a book by title or ID \n4. Diplay all registered books \n5. View all registered members \n6. Add a member \n7. Remove a member \n8. Load in previous Library \n9. Save current library to file" << endl;
                    cin >> choice2;
                    //enter switch for admin options
                    switch(choice2){
                    case 0:
                        doneAdm = true;
                        break;
                    case 1:
                        //get all values from user
                        cout << "Add a book selected.\n--------------\n";
                        cout << "Enter Title: " << endl;
                        cin >> ti;
                        cout << "Enter Author: " << endl;
                        cin >> au;
                        cout << "Enter Genre: " << endl;
                        cin >> gen;
                        cout << "Enter Page Count: " << endl;
                        cin >> pgC;

                        //generate book ID - B then 3 random numbers?
                        srand(static_cast<unsigned>(time(nullptr)));
                        num = rand() % 201;
                        bID = "B"+to_string(num);
                        cout << bID << endl;
                        //get type
                        cout << "Please enter B for book, M for magazine or J for journal." << endl;
                        cin >> type;
                        if (type != "B" || type != "M" || type != "J"){ //-------------------------------------------------------------------------------------HERE
                            cout << "Incorrect entered value, \nPlease enter B for book, M for magazine or J for journal." << endl;
                            cin >> type;
                        }

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
                        break;
                    case 2:
                        cout << "Remove Book selected.\n--------------\n";
                        cout << "Enter the Book ID of the book you wish to remove: " << endl;
                        cin >> bID;
                        Lib.removeLibPub(bID);
                        break;
                    case 3:
                        cout << "Search for Book selected.\n--------------\n";
                        cout << "Enter the Book ID or title to search for:" << endl;
                        cin >> bID;
                        Lib.searchForBook(bID);
                        break;
                    case 4:
                        cout << "Display all Books selected.\n--------------\n" << endl;
                        Lib.dispAllPub();
                        break;
                    case 5:
                        cout << "View all registered members selected.\n--------------\n";
                        Lib.dispAllMemb();
                        break;
                    case 6:
                        cout << "Add new member selected.\n--------------\n";
                        cout << "Please enter the member name: " << endl;
                        cin >> name;
                        //generate member ID
                        srand(static_cast<unsigned>(time(nullptr)));
                        num = rand() % 201;
                        mID = "M"+to_string(num);

                        Lib.addMembList(mID, name);//ID and name
                        break;
                    case 7:
                        cout << "Remove member selected.\n--------------\n";
                        cout << "Enter the ID of the member you wish to delete: " << endl;
                        cin >> mID;
                        Lib.removeMembList(mID);
                        break;
                    case 8:
                        cout << "Load in previous saved library selected.\n--------------\n";
                        break;
                    case 9:
                        cout << "Save current library selected.\n--------------\n";
                        Lib.saveToFile();
                        break;
                    }
                }   
                break;


            case 2:
                cout << "You have selected Member options.\n--------------\n";
                while (doneMem == false){
                    //find the member they are trying to do stuff with and store
                    cout << "Please enter the ID or name of the member you are:" << endl;
                    cin >> mID;
                    /**
                    while (!Lib.searchForMemb(mID)){
                        cout << "Error: The user does not exist. Please enter again" << endl;
                        cout << "Please enter the ID or name of the member you are:" << endl;
                        cin >> mID;
                    }*/

                    //start switch for this 
                    cout << "Enter a number to make your selection: \n1. Borrow a book \n2. Return a book \n3. View all borrowed books" << endl;
                    cin >> choice3;
                    switch(choice3){
                        case 1:
                            cout << "Enter the ID of the book you wish to borrow: " << endl;
                            cin >> bID;
                            Lib.borrowPub(bID, mID);
                            break;
                        case 2:
                            cout << "Enter the ID of the book you wish to return." << endl;
                            cin >> bID;
                            Lib.returnPub(bID, mID);
                            break;
                        case 3:
                            Lib.viewBorrowed(mID);
                        case 0:
                            cout << "Exiting...\n--------------\n";
                            doneMem == true;
                            break;
                    }
                }
                break;
            case 0:
                cout << "Exiting...\n--------------\n";
                doneAll == true;
                return 0;
        }
    }
    return 0;
}