#include "member.cpp"
#include <string>
using namespace std;

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