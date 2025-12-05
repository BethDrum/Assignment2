#include "RunFunc.h"

#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    Library Lib;
    int choice1;
    int choice2;
    int choice3;
    bool doneAll = false;
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
    string typeSearch = "";
    string searchID = "";
    RunFunc run;

    //menu for testing/running
    while (doneAll == false){
        bool doneAdm = false;
        bool doneMem = false;
        bool checkM = false;

        cout << "Please enter if you wish to access the options for: \n1. Admins \n2. Members \n3. Done" << endl;
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
                        run.runAddPub();
                        break;
                    case 2:
                        cout << "Remove Book selected.\n--------------\n";
                        run.runRemovePub();
                        break;
                    case 3:
                        cout << "Search for Book selected.\n--------------\n";
                        run.runSearch();
                        break;
                    case 4:
                        cout << "Display all Books selected.\n--------------\n" << endl;
                        run.runDisplayP();
                        break;
                    case 5:
                        cout << "View all registered members selected.\n--------------\n";
                        run.runDisplayM();
                        break;
                    case 6:
                        cout << "Add new member selected.\n--------------\n";
                        run.runAddMember();
                        break;
                    case 7:
                        cout << "Remove member selected.\n--------------\n";
                        run.runRemoveMember();
                        break;
                    case 8:
                        cout << "Load in previous saved library selected.\n--------------\n"; //NEEDS THING TO ENTER YOUR OWN FILE--------------------------------------
                        run.runReadFile();
                        break;
                    case 9:
                        cout << "Save current library selected.\n--------------\n";
                        run.runSaveFile();
                        break;
                    }
                }
                break;
            case 2:
                cout << "You have selected Member options.\n--------------\n";
                //find the member they are trying to do stuff with and store
                cout << "Please enter the ID or name of the member you are:" << endl;
                cin >> mID;
                checkM = run.checkMemb(mID);
                if (!checkM){
                    cout << "Member does not exist" << endl;
                    break;
                }
                while (doneMem == false){
                    cout << "Enter a number to make your selection: \n1. Borrow a book \n2. Return a book \n3. View all borrowed books" << endl;
                    cin >> choice3;
                    switch(choice3){
                        case 1:
                            run.runBorrow(bID, mID);
                            break;
                        case 2:
                            run.runReturn(bID, mID);
                            break;
                        case 3:
                            run.runViewBorrowed(mID);
                            break;
                        case 0:
                            cout << "Exiting...\n--------------\n";
                            doneMem = true;
                            break;
                    }
                }
                break;
            case 0:
                cout << "Exiting...\n--------------\n";
                doneAll = true;
                break;
            return 0;
        }
    }
    return 0;
}