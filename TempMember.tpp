#include "TempMember.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
vector<T> TempMember<T>::getAllBooks(){
    vector<T> allB;
    for (const T bk : bookList){
        allB.push_back(bk);
    }
    return allB;
}

//to add a book to the members book list ('Borrow')
template <typename T>
bool TempMember<T>::addPub(const T& bk){
    try{
        bookList.push_back(bk);
    }catch (exception e){
        return false;
    }
    return true;
}

//view all books
template <typename T>
void TempMember<T>::viewBooks(){
    for (BorrowedBk bk : bookList){
        cout << bk.bookID << " Borrowed on: " << bk.date << " ";
    }
}

//remove book from book list ('Return')
template <typename T>
bool TempMember<T>::removePub(string pubID){
    for (auto i = bookList.begin(); i != bookList.end(); ++i){
        //ensure book is held in the list
        if (i->bookID == pubID){
            try{
                bookList.erase(i);
            } catch (exception e){
                //removal failed
                return false;
            }
            return true;
        }
    }
    return false;
}
