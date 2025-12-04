#include "Publication.h"
#include "Member.h"

#include <string>
#include <iostream>
#include <vector>
using namespace std;

//get & sets for memberID and name
string Member::getMembID(){
    return memberID;
}

void Member::setMembID(string newMemID){
    memberID = newMemID;
}

string Member::getName(){
    return name;
}

void Member::setName(string newName){
    name = newName;
}

//to add a book to the members book list ('Borrow')
bool Member::addPub(string pbID){
    try{
        bookList.push_back(pbID);
    }catch (exception e){
        return false;
    }
    return true;
}

/**
//to add a book to the members book list ('Borrow')
void Member::addBook(int bID, string ti, string au, string gen, int pgC, bool ava){
    Book bk(bID, ti, au, gen, pgC, ava);
    bookList.push_back(bk);
}*/


//remove book from book list ('Return')
bool Member::removePub(string pubID){
    int i = 0;
    for (string pub : bookList){
        if (pub == pubID){
            try{
                bookList.erase(bookList.begin() + i);
            } catch (exception e){
                //removal failed
                return false;
            }
            return true;
        }
        i++;
    }
}

//add to reserved list
bool Member::addRes(string pID){
    try{
        reserveList.push_back(pID);
    }catch (exception e){
        return false;
    }
    return true;
}

//remove from reserved list
bool Member::removeRes(string pubID){
    int i = 0;
    for (string pb : reserveList){
        if (pb == pubID){
            try{
                reserveList.erase(reserveList.begin() + i);
            } catch (exception e){
                //removal failed
                return false;
            }
            return true;
        }
        i++;
    }
}

bool Member::checkRes(string pubID){
    for (string pb : reserveList){
        if (pb == pubID){
            return true;
        }
    }
    return false;
}


//constructor
Member::Member(string membID, string nam){
    memberID = membID;
    name = nam;
    bookList.clear();
}


void Member::viewBooks(){
    for (string bk : bookList){
        cout << bk << " ";
    }
}

void Member::viewMemb(){
    cout << "ID: " << getMembID() << " Name: " << getName();
}

vector<string> Member::getAllBooks(){
    vector<string> allB;
    for (string bk : bookList){
        allB.push_back(bk);
    }
    return allB;
}

void Member::setDateB(time_t date){
    dateBorrowed = date;
}

time_t Member::getDateB(){
    return dateBorrowed;
}

