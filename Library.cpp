#include "Member.cpp"
#include "Book.cpp"

#include <string>
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Library{
    //vectors
    vector<Member> membList;
    vector<Book> libBookList;

    //to add a member
    void addMembList(int membID, string nam, int bkList){
        Member memb(membID, nam);
        membList.push_back(memb);
    }

    //remove members
    void removeMembList(int membID){
        for (Member mem : membList){
            if (mem.getMembID == membID){
                mem.pop_back();
            }
        }
    }

    //to add a book to the library
    void addLibBook(int bID, string ti, string au, string gen, int pgC, bool ava){
        Book book(bID, ti, au, gen, pgC, ava);
        libBookList.push_back(book);
    }

    //remove book from library
    void removeLibBook(int bookID){
        for (Book bk : libBookList){
            if (bk.getBookID == bookID){
                bk.pop_back();
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
            //if the member exists
            if (mem.getMembID() == memID){
                //set the book in the library to be unavailiable
                for (Book bk : libBookList){
                    if (bk.getBookID() == bkID){
                        bk.setAvail(false);
                    }
                    //add the book to the member book list
                    mem.addBook(bk)
                }
            }
        }
    }

    //return book
    void borrowBook(int bkID, int memID){
        for (Member mem : membList){
            //if the member exists
            if (mem.getMembID() == memID){
                //set the book in the library to be availiable if book exists
                for (Book bk : libBookList){
                    if (bk.getBookID() == bkID){
                        bk.setAvail(true);
                    }
                    //remove the book from the member book list
                    mem.addBook(bk)
                }
            }
        }
    }

    //read library info from file
    void readFromFile(string fileName){
        string line;
        int i = 0;
        vector<string> v;

        //open file
        ifstream reader(fileName);

        if (!reader){
            cout << "Error on opening file" << endl;
            return;
        }

        while(getline(reader, lines)){
            vector<string> single = split(lines);
            
            for (string s : single){
                v.push_back(line);
            }
        }

        reader.close();
        
        for(int i=0; i<v.size; i++){
            cout << v[i] << endl;
        }

        return 0;
    }
};

string split(string str){
    vector<string> tokens;
    string token;
    stringstream ss(str);

    while (ss >> token){
        tokens.push_back(token);
    }
    return tokens;
}