//#include "Member.h"
#include "Book.h"

#include <string>
using namespace std;

//get & set for bookID
int Book::getBookID(){
    return bookID;
}

void Book::setBookID(int newBookID){
    bookID = newBookID;
}
//get & set for title
string Book::getTitle(){
    return title;
}

void Book::setTitle(string newTitle){
    title = newTitle;
}

//get & set for author
string Book::getAuthor(){
    return author;
}

void Book::setAuthor(string newAuthor){
    author = newAuthor;
}

//get & set for genre
string Book::getGenre(){
    return genre;
}

void Book::setGenre(string newGenre){
    genre = newGenre;
}

//get & set for page count
int Book::getPgCount(){
    return pgCount;
}

void Book::setPgCount(int newPgCount){
    pgCount = newPgCount;
}

//get & set for availiability
bool Book::getAvai(){
    return avai;
}

void Book::setAvail(bool newAvai){
    avai = newAvai;
}

//constructor
Book::Book(int bID, string ti, string au, string gen, int pgC, bool ava){
    bookID = bID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = ava;
}