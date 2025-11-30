#include "Book.h"
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
void Member::addBook(string bID, string ti, string au, string gen, int pgC){
    Book book(bID, ti, au, gen, pgC);
    bookList.push_back(book);
}

/**
//to add a book to the members book list ('Borrow')
void Member::addBook(int bID, string ti, string au, string gen, int pgC, bool ava){
    Book bk(bID, ti, au, gen, pgC, ava);
    bookList.push_back(bk);
}*/

/**
//remove book from book list ('Return')
void Member::removeBook(int place){
    //bookList.erase(place);
}*/

//constructor
Member::Member(string membID, string nam){
    memberID = membID;
    name = nam;
    bookList.clear();
}

//print all books - WHY NOT WORKING
void Member::allBooks(){
    for (Book bk : bookList){
        cout << bk.getBookID();
    }
}

