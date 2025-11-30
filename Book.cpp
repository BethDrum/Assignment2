//#include "Member.h"
#include "Book.h"

#include <string>
using namespace std;

//get & set for bookID
string Book::getBookID(){
    return bookID;
}

void Book::setBookID(string newBookID){
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
int Book::getAvai(){
    return avai;
}

void Book::setAvail(int newAvai){
    avai = newAvai;
}

//constructor
Book::Book(string bID, string ti, string au, string gen, int pgC){
    bookID = bID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = 1;
}

Book::Book(string bID, string ti, string au, string gen, int pgC, int ava){
    bookID = bID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = ava;
}