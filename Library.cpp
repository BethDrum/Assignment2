#include "Member.h"
#include "Publication.h"
#include "Library.h"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <stdexcept>
using namespace std;

//template <class T>

//to add a member
bool Library::addMembList(string membID, string nam){
    Member memb(membID, nam);
    try{
        membList.push_back(memb);
    }catch (exception e){
        cout << "Error adding to vector" << endl;
        return false;
    }
    return true;
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
bool Library::addLibBook(string pID, string ti, string au, string gen, int pgC){
    Book book(pID, ti, au, gen, pgC);
    try{
        readingList.push_back(new Book(book));
    } catch (exception e){
        cout << "Error adding book" << endl;
        return false;
    }
    return true;
}

//add journal to the library
bool Library::addLibJour(string pID, string ti, string au, string gen, int pgC, int vol){
    Journal jour(pID, ti, au, gen, pgC, vol);
    try{
        readingList.push_back(new Journal(jour));
    } catch (exception e){
        cout << "Error adding journal" << endl;
        return false;
    }
    return true;
}

//add magazine to the library
bool Library::addLibMag(string pID, string ti, string au, string gen, int pgC, int issueN){
    Magazine mag(pID, ti, au, gen, pgC, issueN);
    try{
        readingList.push_back(new Magazine(mag));
    } catch (exception e){
        cout << "Error adding journal" << endl;
        return false;
    }
    return true;
}

//remove book from library
bool Library::removeLibPub(string readingID){
    int i = 0;
    for (Publication* pub : readingList){
        if (pub->getPubID() == readingID){
            try{
                readingList.erase(readingList.begin() + i);
            } catch (exception e){
                cout << "Remove from reading list failed" << endl;
                return false;
            }
            return true;
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
        mem.viewBooks();
    }
}

//borrow book
bool Library::borrowPub(string pbID, string memID){
    for (Member& mem : membList){
        //if the member exists
        if (mem.getMembID() == memID){
            //set the book in the library to be unavailiable
            for (Publication* pb : readingList){
                if (pb->getPubID() == pbID){
                    //check if the book is availiable
                    if (pb->getAvai() == 0){
                        cout << "Publication not availiable" << endl;
                        return false;
                    }
                    //set to false
                    pb->setAvail(0);
                    //add the publication type to the member book list
                    if (!mem.addPub(pb->getPubID())){
                        cout << "Error when adding publication to member class." << endl;
                        return false;
                    }else{
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//return book
bool Library::returnPub(string pbID, string memID){
    int i=0;
    for (Member mem : membList){
        //if the member exists
        if (mem.getMembID() == memID){
            //remove the book from the member book list
            if (!(mem.removePub(pbID))){
                cout << "Error removing from the member book list." << endl;
                return false;
            }else{
                //the publication has been succesfully removed
                //if the ID is the same as that returning, make availiable again
                for (Publication* pb : readingList){
                    if (pb->getPubID() == pbID){
                        pb->setAvail(1);
                    }
                }
                return true;
            }
            i++;
        }
    }
    cout << "Memeber not found" << endl;
    return false;
}

void Library::viewBorrowed(string mID){
    for (Member& mem : membList){
        //if the member exists
        if (mem.getMembID() == mID){
            mem.viewBooks();
        }
    }
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
int Library::readFromFile(string fileNameBooks, string fileNameMembers){
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



    //open file
    ifstream reader(fileNameBooks);

    if (!reader){
        cout << "Error on opening books file" << endl;
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

        //if only 6 values in this line, its a book so add as that
        if (single.size() == 6){
            Book book(id, ti, au, gen, pgC, ava);
            try{
                readingList.push_back(new Book(book));
            } catch (exception e){
                cout << "Error adding book" << endl;
            }
        //else its a journal or magazine, check type and store correspondingly
        }else{
            int extraInfo = stoi(single[6]);
            type = single[7];
            if (type == "MAG"){
                Magazine mag(id, ti, au, gen, pgC, extraInfo, ava);
                try{
                readingList.push_back(new Magazine(mag));
                } catch (exception e){
                    cout << "Error adding journal" << endl;
                }
            }if (type == "JOUR"){
                Journal jour(id, ti, au, gen, pgC, extraInfo, ava);
                try{
                    readingList.push_back(new Journal(jour));
                } catch (exception e){
                    cout << "Error adding journal" << endl;
                }
            }
        }
    }
    reader.close();

    //for members
    ifstream reader2(fileNameMembers);

    if (!reader2){
        cout << "Error on opening members file" << endl;
    }

    //read in full line
    while(getline(reader2, mLines)){
        //split by the spaces
        vector<string> mSingle = split(mLines);
        //assign spaces to their acccording things
        mID = mSingle[0];
        mName = mSingle[1];
        Member memb(mID, mName);
        //book list
        for (int i = 2; i < mSingle.size(); i++){
            if (!memb.addPub(mSingle[i])){
                cout << "Error when adding publication to member class." << endl;
            }
        }
        try{
            membList.push_back(memb);
        }catch (exception e){
            cout << "Error adding to vector" << endl;
        }

    }
    //close reader and return
    reader2.close();
    return 0;
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
            writerP << pb->getPubID() << " " << '"' << pb->getTitle() << '"' << " " << '"' << pb->getAuthor() << '"' << " " << '"' << pb->getGenre() << '"' << " " << pb->getPgCount() << " " << pb->getAvai() << endl;
        }else if(pb->getType()=="MAG"){
            Magazine* mg = static_cast<Magazine*>(pb);
            writerP << mg->getPubID() << " " << '"' << mg->getTitle() << '"' << " " << '"' << mg->getAuthor() << '"' << " " << '"' << mg->getGenre() << '"' << " " << mg->getPgCount() << " " << mg->getAvai() << " " << mg->getIssueN() << endl;
        }else if(pb->getType()=="JOUR"){
            Journal* jou = static_cast<Journal*>(pb);
            writerP << jou->getPubID() << " " << '"' << jou->getTitle() << '"' << " " << '"' << jou->getAuthor() << '"' << " " << '"' << jou->getGenre() << '"' << " " << jou->getPgCount() << " " << jou->getAvai() << " " << jou->getVol() << endl;
        }
    }
    writerP.close();

    ofstream writerM("membersTEST.txt");
    if (!writerM){
        cerr << "Error opening file for output" << endl;
        return false;
    }

    for (Member mem : membList){
        vector<string> allBooks;
        allBooks = mem.getAllBooks();
        writerM << mem.getMembID() << " " << mem.getName() << " ";
        for (int i=0; i< allBooks.size(); i++){
            writerM << allBooks[i] << " ";
        }
        writerM << endl;
    }
    writerM.close();

    return true;
}

//JUST NEEDS MATH - should track due date then calc penalties - can be different for type
void Library::checkReturn(int outYr, int outMon, int outDay){
    //get day
    time_t currentDate = time(0);
    tm *currDate = localtime(&currentDate);

    cout << "Year: " << 1900+currDate->tm_year << endl;
    cout << "Month" << 1+currDate->tm_mon << endl;
    cout << "Day:" << currDate->tm_mday << endl;

    int yr = 1900+currDate->tm_year;
    int mon = 1+currDate->tm_mon;
    int day = currDate->tm_mday;

    //calculate penalty
    //all have a month to return, 10 days late is £10, 20 days late is £20 and above a month late is £40
    //if (){

    //}

    //check if past current day
}

/** 
//multi criteria search - title, author, genre, availiability NEEDS TEMPLATE SO CAN DO AVAILIABILITY - ALSO LIKE... IS THIS A FILTER THING???
void Library::multiSearch(string data){
    int choice;
    //cout << "Please choose what you are searching for: \n1. Title, \n2. Author, \n3. Genre, \n4. Availability \n(0 to exit)" << endl;
    //cin >> choice;
    //switch(choice){
    for (Publication* pb : readingList){
        if(pb->getTitle() == data){
            cout << "found title" << endl;
        }else if(pb->getAuthor() == data){
            cout << "found author" << endl;
        }else if(pb->getGenre() == data){
            cout << "found author" << endl;
        }//ADD FOR AVAILABILITY
    }
}*/

//search for book
void Library::searchForBook(string searchID, string type){
    bool found = false;
    int distan = 0;
    string bestCase = "";
    int topDist = 100000000;
    string bestMatch = "";

    for (Publication* pb : readingList){
        if (type ==  "T"){
            if (pb->getTitle() == searchID){
                pb->viewInfo(); //ONLY BE ONE
                found = true;
                return;
            }
        }else if (type == "A"){ //needs to print all availiable - CHECK
            if (pb->getAuthor() == searchID){ 
                pb->viewInfo();
                found = true;
            }
        }else if (type == "G"){
            if (pb->getGenre() == searchID){ // neds to print all with that genre? - CHECK
                pb->viewInfo();
                found = true;
            }
        }else if (type == "AV"){
            if (pb->getAvai() == stoi(searchID)){ 
                pb->viewInfo();
                found = true;
            }
        }else if (type == "ID"){
            if (pb->getPubID() == searchID){ //ONLY BE ONE
                pb->viewInfo();
                found = true;
                return;
            }
        }

        if (!found){
            if (type ==  "T"){
                distan = fuzzySearch(searchID, pb->getTitle());
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }else if (type == "A"){
                distan = fuzzySearch(searchID, pb->getAuthor());
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }else if (type == "G"){
                distan = fuzzySearch(searchID, pb->getGenre());
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }else if (type == "AV"){ //DOES THIS NEED FUZZY SEARCHED???
                //----
            }else if (type == "ID"){
                distan = fuzzySearch(searchID, pb->getPubID());
                if (distan <= topDist){
                    topDist = distan;
                    bestMatch = pb->getPubID();
                }
            }
        }
    }

    for (Publication* pbF : readingList){
        if(pbF->getPubID() == bestMatch){ //print all matches
            pbF->viewInfo();
        }
    }
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