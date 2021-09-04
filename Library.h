#include <iostream>
#include <vector>

using namespace std;

class Visitor;

void Print (string (value), int i) {
    string name = value;
    while (name[i] != '_' && i< name.size()) {
        cout << name[i];
        i++;}
    if (i != name.size()) {
        cout << " ";
        i++;
        Print (name, i);
    }
}

class Library{
protected:
    vector<string> name_v;
    vector<string> author_v;
public:

    Library () {}
    Library (vector<string> name_v,  vector<string> author_v) : name_v(name_v), author_v(author_v) {}
    ~Library() = default;
    vector<string> GetNameBooks() {
        return name_v;
    };
    vector<string> GetAuthorBooks() {
        return author_v;
    };

   void GetBook(int x, vector<string> name_v,  vector<string> author_v){
       int i = 0;
       cout << "Name: ";
       Print (name_v[x], i);
       cout << "| Author: ";
       i = 0;
       Print(author_v[x], i);
       cout<<endl;
   }
};

class Librarian : public Library {
protected:
    bool check = true;
    friend class Visitor;
public:

     void SearchBookName(string name, vector<string> name_v, vector<string> author_v) {
         check = true;
        for (int x = 0; x< name_v.size(); x++)  {
            if (name == name_v[x]) {
                GetBook(x, name_v, author_v);
                check = false;
                break;}
        }
        if (check) {cout <<"Sorry, but we don't have the book you're looking for.(("<<endl;}
    }

   void SearchBookAuthor(string author, vector<string> name_v, vector<string> author_v) {
       check = true;
        for (int x = 0; x < author_v.size(); x++)  {
            if (author == author_v[x]) {
                GetBook(x, name_v, author_v);
                check = false;
                break;}
        }
       if (check) {cout <<"Sorry, but we don't have the book you're looking for.(("<<endl;}
}

    void SearchBookName(string name, string author, vector<string> name_v, vector<string> author_v) {
        check = true;
        for (int x = 0; x < author_v.size(); x++) {
            if (author == author_v[x] && name == name_v[x]) {
                GetBook(x,name_v, author_v);
                check = false;
                break;}
        }
        if (check) {cout <<"Sorry, but we don't have the book you're looking for.(("<<endl;}
    }
};

class Visitor : public Library {
protected:
 string name, author;
 bool check1, check2;

public:
    void SearchVisitor (Librarian &B, Library &A) {

        cout << "Welcome to the Library!" << endl;
        cout << "Do you know the name of the book you need?" << endl;
        cout << "|yes (1)| no (0)| ";
        cin >> check1;
        if (check1) {
            cout << "Enter the name of the book: "<< endl;
            cout << "(Use \"_\" instead of a space)"<<endl;
            cin >> name;
        }
        cout << "Do you know the author of the book you need?" << endl;
        cout << "|yes (1)| no (0)| ";
        cin >> check2;
        if (check2) {
            cout << "Enter the author of the book: " << endl;
            cout << "(Use \"_\" instead of a space)" <<endl;
            cin >> author;
        }
        if (check1 && check2) {
            B.SearchBookName(name, author, A.GetNameBooks(), A.GetAuthorBooks());
        } else if (check1) {
            B.SearchBookName(name, A.GetNameBooks(), A.GetAuthorBooks());
        } else if (check2) {
            B.SearchBookAuthor(author, A.GetNameBooks(), A.GetAuthorBooks());
        } else {
            cout << "Think about what kind of book you want"
                    "\nand come back later when you find out the name of the book or the author.";
        }
    }
};


#ifndef UNTITLED18_LIBRARY_H
#define UNTITLED18_LIBRARY_H

#endif //UNTITLED18_LIBRARY_H
