#include "Book.cpp"
#include <string>
#include <vector>
using namespace std;

class Member{
    private: 
        int memberID;
        string name;
        vector<Book> bookList;

    public:
        //get & sets for memberID and name
        int getMembID(){
            return memberID;
        }

        void setMembID(int newMemID){
            memberID = newMemID;
        }

        string getName(){
            return name;
        }

        void setName(string newName){
            name = newName;
        }

        //to add a book to the members book list
        void addBook(int bID, string ti, string au, string gen, int pgC, bool ava){
            Book book(bID, ti, au, gen, pgC, ava);
            bookList.push_back(book);
        }

        //remove book from book list
        void removeBook(Book book){
            bookList.erase(book);
        }

        //constructor
        Member(int membID, string nam){
            memberID = membID;
            name = nam;
            bookList.clear();
        }
};
