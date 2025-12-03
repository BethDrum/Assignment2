#include "Publication.h"

#include <string>
#include <iostream>
using namespace std;

//GETS AND SETS FOR PUBLICATION PARENT CLASS
//get & set for bookID
string Publication::getPubID(){
    return pubID;
}

void Publication::setPubID(string newBookID){
    pubID = newBookID;
}
//get & set for title
string Publication::getTitle(){
    return title;
}

void Publication::setTitle(string newTitle){
    title = newTitle;
}

//get & set for author
string Publication::getAuthor(){
    return author;
}

void Publication::setAuthor(string newAuthor){
    author = newAuthor;
}

//get & set for genre
string Publication::getGenre(){
    return genre;
}

void Publication::setGenre(string newGenre){
    genre = newGenre;
}

//get & set for page count
int Publication::getPgCount(){
    return pgCount;
}

void Publication::setPgCount(int newPgCount){
    pgCount = newPgCount;
}

//get & set for availiability
int Publication::getAvai(){
    return avai;
}

void Publication::setAvail(int newAvai){
    avai = newAvai;
}

string Publication::getType(){
    return type;
}

//view info
void Publication::viewInfo(){
    cout << "ID: " << pubID << " Title: " << title << " Author: " << author << " Genre: " << genre << " Page Count : " << pgCount << " Availiability: " << avai << endl;
}

//BOOK
//constructor for books
Book::Book(string pID, string ti, string au, string gen, int pgC){
    pubID = pID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = 1;
    type = "BOOK";
}

Book::Book(string pID, string ti, string au, string gen, int pgC, int ava){
    pubID = pID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = ava;
    type = "BOOK";
}

//view info
void Book::viewInfo() {
    cout << "ID: " << pubID << " Title: " << title << " Author: " << author << " Genre: " << genre << " Page Count : " << pgCount << " Availiability: " << avai << endl;
}

//MAGAZINE
//gets and sets
int Magazine::getIssueN(){
    return issueNum;
}

void Magazine::setIssueN(int newIssueN){
    issueNum = newIssueN;
}

//constructor
Magazine::Magazine(string pID, string ti, string au, string gen, int pgC, int issueN){
    pubID = pID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = 1;
    issueNum = issueN;
    type = "MAG";
}

Magazine::Magazine(string pID, string ti, string au, string gen, int pgC, int issueN, int ava){
    pubID = pID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = ava;
    issueNum = issueN;
    type = "MAG";
}

//view info
void Magazine::viewInfo() {
    cout << "ID: " << pubID << " Title: " << title << " Author: " << author << " Genre: " << genre << " Page Count : " << pgCount << " Issue Number: " << issueNum << " Availiability: " << avai << endl;
}

//JOURNAL
int Journal::getVol(){
    return volume;
}

void Journal::setVol(int newVol){
    volume = newVol;
}

//constructor
Journal::Journal(string pID, string ti, string au, string gen, int pgC, int vol){
    pubID = pID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = 1;
    volume = vol;
    type = "JOUR";
}

Journal::Journal(string pID, string ti, string au, string gen, int pgC, int vol, int ava){
    pubID = pID;
    title = ti;
    author = au;
    genre = gen;
    pgCount = pgC;
    avai = ava;
    volume = vol;
    type = "JOUR";
}

//view info
void Journal::viewInfo(){
    cout << "ID: " << pubID << " Title: " << title << " Author: " << author << " Genre: " << genre << " Page Count : " << pgCount << " Volume: " << volume << " Availiability: " << avai << endl;
}