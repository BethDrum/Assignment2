#include "Library.h"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <cctype>
using namespace std;

//to add a member
void Library::addMembList(string membID, string nam){
    Member<BorrowedBk> memb(membID, nam);
    try{
        membList.push_back(memb);
    }catch (exception e){
        cout << "Error adding to vector" << endl;
        return;
    }
}

//remove members
bool Library::removeMembList(string membID){
    int i = 0;
    for (Member mem : membList){
        if (mem.getMembID() == membID){
            try{
                membList.erase(membList.begin() + i);
            }catch (exception e){
                cout << "Error removing from vector" << endl;
                return false;
            }
            return true;
        }
        i++;
    }
    cout << "Member does not exist" << endl;
    return false;
}

//search for member
bool Library::searchForMemb(string searchID){
    for (Member mem : membList){
        if(mem.getMembID() == searchID){
            mem.viewMemb();
            return true;
        }else if(mem.getName() == searchID){
            mem.viewMemb();
            return true;
        }
    }
    return false;
}

//to add a book to the library
void Library::addLibBook(string pID, string ti, string au, string gen, int pgC){
    Book book(pID, ti, au, gen, pgC);
    try{
        readingList.push_back(new Book(book));
    } catch (exception e){
        cout << "Error adding book" << endl;
        return;
    }
}

//add journal to the library
void Library::addLibJour(string pID, string ti, string au, string gen, int pgC, int vol){
    Journal jour(pID, ti, au, gen, pgC, vol);
    try{
        readingList.push_back(new Journal(jour));
    } catch (exception e){
        cout << "Error adding journal" << endl;
        return;
    }
}

//add magazine to the library
void Library::addLibMag(string pID, string ti, string au, string gen, int pgC, int issueN){
    Magazine mag(pID, ti, au, gen, pgC, issueN);
    try{
        readingList.push_back(new Magazine(mag));
    } catch (exception e){
        cout << "Error adding journal" << endl;
        return;
    }
}

//remove book from library
void Library::removeLibPub(string readingID){
    int i = 0;
    for (Publication* pub : readingList){
        if (pub->getPubID() == readingID){
            try{
                readingList.erase(readingList.begin() + i);
            } catch (exception e){
                cout << "Remove from reading list failed" << endl;
                return;
            }
        }
        i++;
    }
}

//display all books
void Library::dispAllPub(){
    for (Publication* pb : readingList){
        if (pb->getType()=="BOOK"){
            Book* bk = static_cast<Book*>(pb);
            bk->viewInfo();
        }else if(pb->getType()=="MAG"){
            Magazine* mg = static_cast<Magazine*>(pb);
            mg->viewInfo();
        }else if(pb->getType()=="JOUR"){
            Journal* jou = static_cast<Journal*>(pb);
            jou->viewInfo();
        }
    }
}

//display all registerd members
void Library::dispAllMemb(){
    for (Member mem : membList){
        cout << mem.getName() << " " << mem.getMembID() << " Books borrowed: ";
        mem.readingList.viewBooks();
        cout << endl;
    }
}

bool Library::checkMem(string mID){
    for (Member mem : membList){
        if (mem.getMembID() == mID){
            return true;
        }
    }
    return false;
}

//borrow book
bool Library::borrowPub(string pbID, string memID){
    string resChoice = "";
    for (Member<BorrowedBk>& mem : membList){
        //if the member exists
        if (mem.getMembID() == memID){
            //set the book in the library to be unavailiabl
            for (Publication* pb : readingList){
                if (pb->getPubID() == pbID){
                    //check if the book is availiable
                    if (pb->getAvai() == 0){
                        cout << "Publication not availiable" << endl;
                        //give option to add to the reserved list
                        do{
                            cout << "Would you like to reserve this book? Y/N" << endl;
                            cin >> resChoice;
                        }while (resChoice != "Y" && resChoice != "N");
                        
                        if (resChoice == "Y"){
                            mem.addRes(pb->getPubID());
                            cout << "The book has been added to reservations." << endl;
                        }
                        //return false as no book borrowed
                        return false;
                    }
                    //set to false
                    pb->setAvail(0);
                    //add the publication type to the member book list
                    time_t date = getDate();
                    BorrowedBk bk{pb->getPubID(), date};
                    if (!mem.readingList.addPub(bk)){
                        cout << "Error when adding publication to member class." << endl;
                        return false;
                    }else{
                        return true;
                    }
                }
            }
            return false;
        }
    }
    return false;
}

//return book
void Library::returnPub(string pbID, string memID){
    double penalty = 0.0;
    bool returned = false;
    string resChoice = "";

    for (Member<BorrowedBk>& mem : membList){
        //if the member exists
        if (mem.getMembID() == memID){
            //remove the book from the member book list
            if (!(mem.readingList.removePub(pbID))){
                cout << "Error removing from the member book list." << endl;
                return;
            }else{
                //the publication has been succesfully removed
                //if the ID is the same as that returning, make availiable again
                for (Publication* pb : readingList){
                    if (pb->getPubID() == pbID){
                        pb->setAvail(1);
                        //check if theres a reservation in place for this book
                    }
                    //check for any penalites
                    if (pb->getPubID() == pbID){
                        penalty = checkPenalty(mem.getDateB(), pb->getType());
                        if (penalty > 0){
                            cout << "You have a penalty fee to pay of: " << penalty << endl;
                        }
                    }
                }
                returned = true;
                break;
            }
        }
    }

    //check for reservation if its been returned
    if (returned == true){
        for (Member<BorrowedBk>& mem : membList){
            if (mem.checkRes(pbID)){
                do{
                    cout << mem.getMembID() << " (" << mem.getName() << ") " << " The book you reserved - " << pbID << " - is now availiable. \nWould you like to borrow it? Y/N" << endl;
                    cin >> resChoice;
                }while (resChoice != "Y" && resChoice != "N");
                
                if (resChoice == "Y"){
                    borrowPub(pbID, mem.getMembID());
                }
                break;
            }
        }
    }
    if (!returned){
        cout << "Memeber not found" << endl;
    }
}

void Library::viewBorrowed(string mID){
    for (Member mem : membList){
        //if the member exists
        if (mem.getMembID() == mID){
            mem.readingList.viewBooks();
        }
    }
    cout << endl;
}

vector<string> Library::split(string str){
    string token;
    vector<string> tokens;
    stringstream ss(str);

    while (ss){
        while (isspace(ss.peek())){
            ss.get();
        }
        //check if there is a quote (for the book title, author etc to not be seperated)
        if (ss.peek() == '"'){
            ss.get();
            getline(ss, token, '"');
        }else{
            if(!(ss >> token)){
                break;
            };
        }
        tokens.push_back(token);
    }
    return tokens;
}   

//read library info from file
bool Library::readFromFile(string fileNameBooks, string fileNameMembers){
    string lines;
    string mLines;
    vector<string> v;
    string id;
    string ti;
    string au;
    string gen;
    int pgC;
    int ava;
    string type;
    string extraInfo;
    string mID;
    string mName;
    vector <string> books;
    time_t date;
    string bkID;



    //open file
    ifstream reader(fileNameBooks);

    if (!reader){
        cout << "Error on opening books file" << endl;
        return false;
    }

    //read in full line
    while(getline(reader, lines)){
        //split by the spaces
        vector<string> single = split(lines);
        //assign spaces to their acccording things
        id = single[0];
        ti = single[1];
        au = single[2];
        gen = single[3];
        pgC = stoi(single[4]);
        ava = stoi(single[5]);

        cout << single.size() << endl;
        //for no type
        if (single.size() == 6){
            Book book(id, ti, au, gen, pgC, ava);
            try{
                readingList.push_back(new Book(book));
            } catch (exception e){
                cout << "Error adding book" << endl;
                return false;
            }
        }

        //for when type comes im
        //if only 6 values in this line, its a book so add as that
        if (single.size() == 7){
            type = single[6];
            int extraInfo = stoi(single[7]);

            if (type == "BOOK"){
                Book book(id, ti, au, gen, pgC, ava);
                try{
                    readingList.push_back(new Book(book));
                } catch (exception e){
                    cout << "Error adding book" << endl;
                    return false;
                }
            }else if (type == "MAG"){
            //else its a journal or magazine, check type and store correspondingly
                Magazine mag(id, ti, au, gen, pgC, extraInfo, ava);
                try{
                readingList.push_back(new Magazine(mag));
                } catch (exception e){
                    cout << "Error adding journal" << endl;
                    return false;
                }
            }else if (type == "JOUR"){
                Journal jour(id, ti, au, gen, pgC, extraInfo, ava);
                try{
                    readingList.push_back(new Journal(jour));
                } catch (exception e){
                    cout << "Error adding journal" << endl;
                    return false;
                }
            }
        }
    }
    reader.close();

    //for members
    ifstream reader2(fileNameMembers);

    if (!reader2){
        cout << "Error on opening members file" << endl;
        return false;
    }

    //read in full line
    while(getline(reader2, mLines)){
        //split by the spaces
        vector<string> mSingle = split(mLines);

        //assign spaces to their acccording things
        mID = mSingle[0];
        mName = mSingle[1];
        Member<BorrowedBk> memb(mID, mName);
        //book list
        //so it does book then date every other one
        for (int i = 2; i + 1 < mSingle.size(); i+=2){
            bkID = mSingle[i];
            date = static_cast<time_t>(stoi(mSingle[i+1]));
            BorrowedBk bk{bkID, date};
            if (!memb.readingList.addPub(bk)){
                cout << "Error when adding publications to member class." << endl;
                return false;
            }
        }
        membList.push_back(memb);
    }
    //close reader and return
    reader2.close();
    return true;
}


//save library info to file - NEED TO ADD ALL BOOKS FOR THE MEMBER
bool Library::saveToFile(){
    //string fileN = filename+".txt";
    //cout << fileN << endl;

    ofstream writerP("booksTEST.txt");

    if (!writerP){
        cerr << "Error opening file for output" << endl;
        return false;
    }

    for (Publication* pb : readingList){
        if (pb->getType()=="BOOK"){
            Book* bk = static_cast<Book*>(pb);
            writerP << pb->getPubID() << " " << '"' << pb->getTitle() << '"' << " " << '"' << pb->getAuthor() << '"' << " " << '"' << pb->getGenre() << '"' << " " << pb->getPgCount() << " " << pb->getAvai() << "  BOOK" << endl;
        }else if(pb->getType()=="MAG"){
            Magazine* mg = static_cast<Magazine*>(pb);
            writerP << mg->getPubID() << " " << '"' << mg->getTitle() << '"' << " " << '"' << mg->getAuthor() << '"' << " " << '"' << mg->getGenre() << '"' << " " << mg->getPgCount() << " " << mg->getAvai() << "  MAG" << " " << mg->getIssueN() << endl;
        }else if(pb->getType()=="JOUR"){
            Journal* jou = static_cast<Journal*>(pb);
            writerP << jou->getPubID() << " " << '"' << jou->getTitle() << '"' << " " << '"' << jou->getAuthor() << '"' << " " << '"' << jou->getGenre() << '"' << " " << jou->getPgCount() << " " << jou->getAvai()<< "  JOUR" << " " << jou->getVol() << endl;
        }
    }
    writerP.close();

    ofstream writerM("membersTEST.txt");
    if (!writerM){
        cerr << "Error opening file for output" << endl;
        return false;
    }

    for (Member mem : membList){
        writerM << mem.getMembID() << " " << mem.getName() << " ";
        for (auto bk : mem.readingList.getAllBooks()){
            writerM << bk.bookID << " " << bk.date << " ";
        }
        writerM << endl;
    }
    writerM.close();

    return true;
}

double Library::checkPenalty(time_t borDate, string type){
    time_t currDate;
    currDate = getDate();
    double penalty = 0;

    //returns seconds - so all compares must be changed to seconds
    double diff = difftime(currDate, borDate);
    cout << diff << endl;

    //first num in calc is the days
    if (type == "BOOK" && diff > 10*24*60*60){
        //10 days for books
        penalty = 10.00;
        return penalty;
    }else if (type == "MAG" && diff > 11*24*60*60){
        //11 days
        penalty = 15.00;
        return penalty;
    }else if (type == "JOUR" && diff > 12*24*60*60){
        //12 days
        penalty = 20.00;
        return penalty;
    }else{
        //no penalty
        return penalty;
    }
}

//to get the current date
time_t Library::getDate(){
    //get day
    time_t currentDate = time(0);
    tm *currDate = localtime(&currentDate);

    int yr = 1900+currDate->tm_year;
    int mon = 1+currDate->tm_mon;
    int day = currDate->tm_mday; 

    //put into comparable format
    struct tm date;
    date.tm_year = yr - 1900;
    date.tm_mday = day;
    date.tm_mon = mon - 1;
    date.tm_hour = 0;
    date.tm_min  = 0;
    date.tm_sec  = 0;
    date.tm_isdst = -1;
    currentDate = mktime(&date);

    cout << currentDate <<endl;

    return currentDate;
}

string Library::removeSpaces(string str){
    int count = 0;

    for (int i=0; str[i]; i++){
        if (str[i] != ' '){
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
    return str;
}

//search for book
bool Library::searchForBook(string searchID, string type){
    bool found = false;
    int distan = 0;
    string bestCase = "";
    int topDist = 100000000;
    string bestMatch = "";
    bool wildcardFound = false;
    string wildMatch = "";

    //remove spaces from searchID
    searchID = removeSpaces(searchID);
    cout << searchID << endl;
    cout << type << endl;
    for (Publication* pb : readingList){
        cout <<"in pub" << endl;
        if (type ==  "T"){
            cout << removeSpaces(pb->getTitle()) << endl;
            if (removeSpaces(pb->getTitle()) == searchID){
                pb->viewInfo();
                found = true;
            }
        }else if (type == "A"){ //needs to print all availiable
            if (removeSpaces(pb->getAuthor()) == searchID){ 
                pb->viewInfo();
                found = true;
            }
        }else if (type == "G"){
            if (removeSpaces(pb->getGenre()) == searchID){ 
                pb->viewInfo();
                found = true;
            }
            cout << "Gen checked" << endl;
        }else if (type == "AV"){
            try{
                int a = stoi(searchID);
                if (pb->getAvai() == a){ 
                    pb->viewInfo();
                    found = true;
                }
            }catch (const exception& e){
                //search term must be a number. if not it will throw a error
                cerr << "Cannot be av search" << endl;
            }
        }else if (type == "ID"){
            if (removeSpaces(pb->getPubID()) == searchID){ //ONLY BE ONE
                pb->viewInfo();
                found = true;
            }
            cout << "ID checked";
        }

        if (!found){
            string temp;
            cout << "in wild/fluffy " << endl;
            //availiability is not included in the fuzzy or wildcard search as it is 1 character and so forth cannot.
            if (type ==  "T"){
                //wildcard
                if (wildcardS(removeSpaces(pb->getTitle()), searchID)){
                    wildMatch = pb->getPubID();
                    wildcardFound = true;
                }
                //fuzzy
                distan = fuzzySearch(searchID, removeSpaces(pb->getTitle()));
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }else if (type == "A"){
                //wildcard
                if (wildcardS(removeSpaces(pb->getAuthor()), searchID)){
                    wildMatch = pb->getPubID();
                    wildcardFound = true;
                }
                //fuzzy
                distan = fuzzySearch(searchID, removeSpaces(pb->getAuthor()));
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }else if (type == "G"){
                //wildcard
                if (wildcardS(removeSpaces(pb->getGenre()), searchID)){
                    wildMatch = pb->getPubID();
                    wildcardFound = true;
                }
                //fuzzy
                distan = fuzzySearch(searchID, removeSpaces(pb->getGenre()));
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }else if (type == "ID"){
                temp = pb->getPubID();
                //wildcard
                if (wildcardS(removeSpaces(pb->getPubID()), searchID)){
                    wildMatch = pb->getPubID();
                    wildcardFound = true;
                }
                //fuzzy
                distan = fuzzySearch(searchID, removeSpaces(pb->getPubID()));
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }

            if (!temp.empty()){
                if (wildcardS(temp, searchID)){
                    wildMatch = pb->getPubID();
                    wildcardFound = true;
                }
                distan = fuzzySearch(searchID, temp);
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }
        }
    }
    for (Publication* pbF : readingList){
        if (!bestMatch.empty() && pbF->getPubID() == bestMatch){ //print all matches
            pbF->viewInfo();
            found = true;
            break;
        }

        if (wildcardFound == true && pbF->getPubID() == wildMatch){
            pbF->viewInfo();
            found = true;
            break;
        }
    }
    return found;
}

int Library::fuzzySearch(string check, string change){
    //do repetitivly through the entire list with str2 changing to be the next in the list, keeping track of ID and distance away for each - smallest distance is best match and should be used
    string str1 = check;
    string str2 = change;

    int dist = LevenshteinFunc(str1, str2, str1.length(), str2.length());
    return dist;
}

//levenshtein function for fuzzy search - compare simelarity of searched to all names in the list and highest simelarity is shown to user
int Library::LevenshteinFunc(string str1, string str2, int m, int n){
    //ensure books are not empty
    if (m == 0){
        return n;
    }
    if (n == 0){
        return m;
    }

    if (str1[m-1] == str2[n-1]){
        return LevenshteinFunc(str1, str2, m-1,
                                n-1);
    }
    return 1 
        +min(
            //insert
            LevenshteinFunc(str1, str2, m, n-1), 
            min(
                //remove
                LevenshteinFunc(str1, str2, m-1, 
                                    n),
                //replace
                LevenshteinFunc(str1, str2, m-1,
                                    n-1)));
}

//checks if the entered search matches any other values given.
bool Library::wildcardS(string searchID, string pattern){
    int sLen = searchID.length();
    int patLen = pattern.length();
    int i = 0;
    int j = 0;
    int startI = -1;
    int match = 0;

    while (i < sLen){

        //if the next char is a ?
        if (j < patLen && pattern[j] == '?' || pattern[j] == searchID[i]){
            i++;
            j++;
        //if the next char is a *
        }else if (j < patLen && pattern[j] == '*'){
            startI = j;
            match = i;
            j++;
        //no matching wildcard but there has been on previously
        }else if(startI != -1){
            j = startI + 1;
            match ++;
            i = match;
        //else no wildcard
        }else{
            return false;
        }
    }

    while (j < patLen && pattern[j] == '*'){
        j++;
    }

    return j == patLen;
}