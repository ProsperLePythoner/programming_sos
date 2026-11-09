//
// Created by Prosper.dev on 07/08/2026.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Book {
public:
    string title;
    string author;
    int copies = 0;

    // Public constructor with initializer syntax
    Book(string t, string a, int c) :
    title(t), author(a), copies(c) {}

    void borrow_book() {
        copies--;
        cout << "Successfully borrowed book: " << title << "!" << endl;
    }

    void return_book() {
        copies++;
        cout << "Successfully returned book: " << title << "!" << endl;
    }
};

vector<Book> books;

void create_book() {
    string title, author;
    int copies;
    cout << "------ CREATE NEW BOOK ------" << endl;
    cout << "Enter book title: ";
    cin >> title;
    cout << "Enter book author: ";
    cin >> author;
    cout << "Enter number of copies for book '"<< title << "': ";
    cin >> copies;
    Book b(title, author, copies);
    books.push_back(b);
    cout << "\nSuccessfully created new book: " << title << "!" << endl;
}

void borrow_book() {
    cout << "Select a book from below to borrow:" << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i].title << " by " << books[i].author << ". (" << books[i].copies << " copies)" << endl;
    }
    cout << "Your choice (integer number): " << endl;
    int choice;
    cin >> choice;

    if (books[choice - 1].copies > 0) {
        if (choice <= books.size() && choice > 0) {
            books[choice - 1].borrow_book(); // borrow book by index
        } else {
            cout << "[ERROR]: Could not borrow book!" << endl;
        }
    } else {
        cout << "No books available to borrow." << endl;
    }
}

void return_book() {
    cout << "Select a book from below to return:" << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i].title << " by " << books[i].author << ". (" << books[i].copies << " copies)" << endl;
    }
    cout << "Your choice (integer number): " << endl;
    int choice;
    cin >> choice;

    if (choice <= books.size() && choice > 0) {
        books[choice - 1].return_book(); // return book by index
    } else {
        cout << "[ERROR]: Could not return book!" << endl;
    }
}

int main() {
    while (true) {
        cout << "\n\nWelcome to the Library Management System!" << endl;
        cout << "\nChoose an action from below:" << endl;
        cout << "1. Create book\n2. Borrow book\n3. Return book\n4. Exit\n" << endl;
        int action;
        cin >> action;

        switch (action) {
            case 1:
                create_book();
                break;
            case 2:
                borrow_book();
                break;
            case 3:
                return_book();
                break;
            case 4:
                cout << "Exiting..." << endl;
                exit(0);
                break;
            default:
                cout << "[ERROR]: Invalid action!" << endl;
        }
    }
}