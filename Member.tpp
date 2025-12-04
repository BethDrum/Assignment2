#include "Member.h"

#include <string>
#include <iostream>
#include <vector>
using namespace std;

//get & sets for memberID and name
template <typename T>
string Member<T>::getMembID(){
    return memberID;
}

template <typename T>
void Member<T>::setMembID(string newMemID){
    memberID = newMemID;
}

template <typename T>
string Member<T>::getName(){
    return name;
}

template <typename T>
void Member<T>::setName(string newName){
    name = newName;
}

//add to reserved list
template <typename T>
bool Member<T>::addRes(string pID){
    try{
        reserveList.push_back(pID);
    }catch (exception e){
        return false;
    }
    return true;
}

//remove from reserved list
template <typename T>
bool Member<T>::removeRes(string pubID){
    int i = 0;
    for (auto pb : reserveList){
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

template <typename T>
bool Member<T>::checkRes(string pubID){
    for (auto pb : reserveList){
        if (pb == pubID){
            return true;
        }
    }
    return false;
}

//constructor
template <typename T>
Member<T>::Member(string membID, string nam){
    memberID = membID;
    name = nam;
}

template <typename T>
void Member<T>::viewMemb(){
    cout << "ID: " << getMembID() << " Name: " << getName();
}

template <typename T>
void Member<T>::setDateB(time_t date){
    dateBorrowed = date;
}

template <typename T>
time_t Member<T>::getDateB(){
    return dateBorrowed;
}