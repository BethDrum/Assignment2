#include "Member.h"
#include "Book.h"
#include "Library.h"

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

//template <class T>

//to add a member
void Library::addMembList(string membID, string nam){
    Member memb(membID, nam);
    membList.push_back(memb);
}

//remove members
void Library::removeMembList(string membID){
    for (Member mem : membList){
        if (mem.getMembID() == membID){
            membList.pop_back();
        }
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

//display all registerd members
void Library::dispAllMemb(){
    for (Member mem : membList){
        cout << mem.getName() << mem.getMembID() << "\n";
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
                    if (bk.getAvai() == false){
                        cout << "not availiable" << endl;
                        return;
                    }
                    //set to false
                    bk.setAvail(false);
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
                    bk.setAvail(true);
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
