#include "Book.h"
#include "Member.h"
#include <string>
#include <vector>
using namespace std;

//get & sets for memberID and name
int Member::getMembID(){
    return memberID;
}

void Member::setMembID(int newMemID){
    memberID = newMemID;
}

string Member::getName(){
    return name;
}

void Member::setName(string newName){
    name = newName;
}

//to add a book to the members book list ('Borrow')
void Member::addBookNew(int bID, string ti, string au, string gen, int pgC, bool ava){
    Book book(bID, ti, au, gen, pgC, ava);
    bookList.push_back(book);
}

//to add a book to the members book list ('Borrow')
void Member::addBook(Book bk){
    bookList.push_back(bk);
}

//remove book from book list ('Return')
void Member::removeBook(Book book){
    //bookList.erase(book);
}

//constructor
Member::Member(int membID, string nam){
    memberID = membID;
    name = nam;
    bookList.clear();
}

