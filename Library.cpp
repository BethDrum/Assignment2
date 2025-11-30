#include "Member.h"
#include "Book.h"
#include "Library.h"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;

//template <class T>

//to add a member
void Library::addMembList(string membID, string nam){
    Member memb(membID, nam);
    membList.push_back(memb);
}

//remove members
void Library::removeMembList(string membID){
    int i = 0;
    for (Member mem : membList){
        if (mem.getMembID() == membID){
            membList.erase(membList.begin() + i);
            cout << "removed." << endl;
        }
        i++;
    }
}

//search for member
bool Library::searchForMemb(string searchID){
    for (Member mem : membList){
        if(mem.getMembID() == searchID){
            return true;
        }else if(mem.getName() == searchID){
            return true;
        }
    }
    return false;
}

//to add a book to the library
void Library::addLibBook(string bID, string ti, string au, string gen, int pgC){
    Book book(bID, ti, au, gen, pgC);
    libBookList.push_back(book);
}

//remove book from library
void Library::removeLibBook(string bookID){
    int i = 0;
    for (Book bk : libBookList){
        if (bk.getBookID() == bookID){
            libBookList.erase(libBookList.begin() + i);
            cout << "removed." << endl;
        }
        i++;
    }
}


//search for book
void Library::searchForBook(string searchID){
    for (Book bk : libBookList){
        if(bk.getBookID() == searchID){
            cout << "found" << endl;
        }else if(bk.getTitle() == searchID){
            cout << "found" << endl;
        }
    }
}

//display all books
void Library::dispAllBook(){
    for (Book bk : libBookList){
        cout << bk.getBookID() << " " << bk.getTitle() << " " << bk.getAuthor() << " " << bk.getGenre() << " " << bk.getPgCount() << " " << bk.getAvai() << "\n";
    }
}

//display all registerd members
void Library::dispAllMemb(){
    for (Member mem : membList){
        cout << mem.getName() << " " << mem.getMembID() << "\n";
    }
}

//borrow book - NEED TO ADD TRY CATCHES OR SOMETHING FOR ERROR CHECKING
void Library::borrowBook(string bkID, string memID){
    for (Member mem : membList){
        //if the member exists
        if (mem.getMembID() == memID){
            //set the book in the library to be unavailiable
            for (Book bk : libBookList){
                if (bk.getBookID() == bkID){
                    //check if the book is availiable
                    if (bk.getAvai() == 0){
                        cout << "not availiable" << endl;
                        return;
                    }
                    //set to false
                    bk.setAvail(0);
                    //add the book to the member book list
                    mem.addBook(bk.getBookID(), bk.getTitle(), bk.getAuthor(), bk.getGenre(), bk.getPgCount());
                }
            }
        }
    }
}

//return book
void Library::returnBook(string bkID, string memID){
    int i=0;
    for (Member mem : membList){
        //if the member exists
        if (mem.getMembID() == memID){
            //set the book in the library to be availiable if book exists
            for (Book bk : libBookList){
                if (bk.getBookID() == bkID){
                    bk.setAvail(1);
                }
                //remove the book from the member book list
                //mem.removeBook(i);
                i++;
            }
        }
    }
}

vector<string> Library::split(string str){
    string token;
    vector<string> tokens;
    stringstream ss(str);

    while (ss >> token){
        //check if there is a quote (for the book title, author etc to not be seperated)
        if (ss.peek() == '"'){
            ss.get();
            getline(ss, token, '"');
        }else{
            ss >> token;
        }
        tokens.push_back(token);
    }
    return tokens;
}   

//read library info from file
int Library::readFromFile(string fileName){
    string lines;
    vector<string> v;

    //open file
    ifstream reader(fileName);

    if (!reader){
        cout << "Error on opening file" << endl;
    }

    while(getline(reader, lines)){
        vector<string> single = split(lines);
        
        for (string s : single){
            v.push_back(s);
        }
    }

    reader.close();
    
    for(size_t i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}


//save library info to file - NEED TO ADD ALL BOOKS FOR THE MEMBER
bool Library::saveToFile(){
    //string fileN = filename+".txt";
    //cout << fileN << endl;

    ofstream writer("books.txt");

    if (!writer){
        cerr << "Error opening file for output" << endl;
        return false;
    }

    for (Book bk : libBookList){
        writer << bk.getBookID() << '"' << bk.getTitle() << '"' << '"' << bk.getAuthor() << '"' << '"' << bk.getGenre() << '"' << bk.getPgCount() << bk.getAvai() << endl;
    }
    writer.close();

    ofstream writer2("members.txt");
    if (!writer2){
        cerr << "Error opening file for output" << endl;
        return false;
    }

    for (Member mem : membList){
        writer2 << mem.getMembID() << mem.getName() << endl;
    }
    writer2.close();

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

//multi criteria search - title, author, genre, availiability NEEDS TEMPLATE SO CAN DO AVAILIABILITY
void Library::multiSearch(string data){
    int choice;
    //cout << "Please choose what you are searching for: \n1. Title, \n2. Author, \n3. Genre, \n4. Availability \n(0 to exit)" << endl;
    //cin >> choice;
    //switch(choice){
    for (Book bk : libBookList){
        if(bk.getTitle() == data){
            cout << "found title" << endl;
        }else if(bk.getAuthor() == data){
            cout << "found author" << endl;
        }else if(bk.getGenre() == data){
            cout << "found author" << endl;
        }//ADD FOR AVAILABILITY
    }
}