#include <string>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

//ADD CONSTRUCTOR
class Book{
    private:
        int bookID;
        string title;
        string author;
        string genre;
        int pgCount;
        bool avai;

    public:
        //get & set for bookID
        int getBookID(){
            return bookID;
        }

        void setBookID(int newBookID){
            bookID = newBookID;
        }
        //get & set for title
        string getTitle(){
            return title;
        }

        void setTitle(string newTitle){
            title = newTitle;
        }

        //get & set for author
        string getAuthor(){
            return author;
        }

        void setAuthor(string newAuthor){
            author = newAuthor;
        }

        //get & set for genre
        string getGenre(){
            return genre;
        }

        void setGenre(string newGenre){
            genre = newGenre;
        }

        //get & set for page count
        int getPgCount(){
            return pgCount;
        }

        void setPgCount(int newPgCount){
            pgCount = newPgCount;
        }

        //get & set for availiability
        bool getAvai(){
            return avai;
        }

        void setAvail(bool newAvai){
            avai = newAvai;
        }

        //constructor
        Book(int bID, string ti, string au, string gen, int pgC, bool ava){
            bookID = bID;
            title = ti;
            author = au;
            genre = gen;
            pgCount = pgC;
            avai = ava;
        }
};

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

        //list of books contained
        void addBook(int bID, string ti, string au, string gen, int pgC, bool ava){
            Book book(bID, ti, au, gen, pgC, ava);
            bookList.insert(book);
        }

        //constructor
        Member(int membID, string nam){
            memberID = membID;
            name = nam;
            bookList.clear();
        }
};



//INHERITANCE FROM BOOK AND MEMBERS
template <class T>
class Library{
    //linked list?
    set<Member> membList;
    set<Book> libBookList;

    //to add a member
    void addMembList(int membID, string nam, int bkList){
        Member memb(membID, nam);
        membList.insert(memb);
    }

    //remove members
    void removeMembList(int membID){
        for (Member mem : membList){
            if (mem.getMembID == membID){
                mem.erase();
            }
        }
    }

    //to add a book to the library
    void addLibBook(int bID, string ti, string au, string gen, int pgC, bool ava){
        Book book(bID, ti, au, gen, pgC, ava);
        libBookList.insert(book);
    }

    //remove book from library
    void removeLibBook(int bookID){
        for (Book bk : libBookList){
            if (bk.getBookID == bookID){
                bk.erase();
            }
        }
    }

    //search for book
    void searchForBook(T searchID){
        for (Book bk : libBookList){
            if(bk.getBookID() == searchID){
                cout << "found";
            }else if(bk.getTitle() == searchID){
                cout << "found";
            }
        }
    }

    //display all registerd members
    void dispAllMemb(){
        for (Member mem : membList){
            cout << mem << "\n";
        }
    }

    //borrow book
    void borrowBook(int bkID, int memID){
        for (Member mem : membList){
            if (mem.getMembID == memID){
                for (Book bk : libBookList){
                    if (bk.getBookID )
                }
            }
        }
    }
};