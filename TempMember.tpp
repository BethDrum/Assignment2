#include "TempMember.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
vector<T> TempMember<T>::getAllBooks(){
    vector<T> allB;
    for (T bk : bookList){
        allB.push_back(bk);
    }
    return allB;
}

//to add a book to the members book list ('Borrow')
template <typename T>
bool TempMember<T>::addPub(T pbID){
    try{
        bookList.push_back(pbID);
    }catch (exception e){
        return false;
    }
    return true;
}

template <typename T>
void TempMember<T>::viewBooks(){
    for (T bk : bookList){
        cout << bk << " ";
    }
}

//remove book from book list ('Return')
template <typename T>
bool TempMember<T>::removePub(T pubID){
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
