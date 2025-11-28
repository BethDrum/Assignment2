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
void Library::addMembList(int membID, string nam, int bkList){
    Member memb(membID, nam);
    membList.push_back(memb);
}

//remove members
void Library::removeMembList(int membID){
    for (Member mem : membList){
        if (mem.getMembID() == membID){
            membList.pop_back();
        }
    }
}

//to add a book to the library
void Library::addLibBook(int bID, string ti, string au, string gen, int pgC, bool ava){
    Book book(bID, ti, au, gen, pgC, ava);
    libBookList.push_back(book);
}

//remove book from library
void Library::removeLibBook(int bookID){
    for (Book bk : libBookList){
        if (bk.getBookID() == bookID){
            libBookList.pop_back();
        }
    }
}

//search for book
void Library::searchForBook(T searchID){
    for (Book bk : libBookList){
        if(bk.getBookID() == searchID){
            cout << "found";
        }else if(bk.getTitle() == searchID){
            cout << "found";
        }
    }
}

//display all registerd members
void Library::dispAllMemb(){
    for (Member mem : membList){
        cout << mem.getName() << mem.getMembID() << "\n";
    }
}

//borrow book
void Library::borrowBook(int bkID, int memID){
    for (Member mem : membList){
        //if the member exists
        if (mem.getMembID() == memID){
            //set the book in the library to be unavailiable
            for (Book bk : libBookList){
                if (bk.getBookID() == bkID){
                    bk.setAvail(false);
                }
                //add the book to the member book list
                mem.addBook(bk);
            }
        }
    }
}

//return book
void Library::returnBook(int bkID, int memID){
    for (Member mem : membList){
        //if the member exists
        if (mem.getMembID() == memID){
            //set the book in the library to be availiable if book exists
            for (Book bk : libBookList){
                if (bk.getBookID() == bkID){
                    bk.setAvail(true);
                }
                //remove the book from the member book list
                mem.addBook(bk);
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
    int i = 0;
    vector<string> v;

    //open file
    ifstream reader(fileName);

    if (!reader){
        cout << "Error on opening file" << endl;
        return;
    }

    while(getline(reader, lines)){
        vector<string> single = split(lines);
        
        for (string s : single){
            v.push_back(s);
        }
    }

    reader.close();
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}
