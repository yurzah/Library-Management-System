
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#define n 5

using namespace std;


struct Book {
    string name;
    int year;
    string author_name;
    int id;
    bool is_borrowed = false;
} books[n]{};

void getBookStatus(int i) {

    cout << "Book status: ";

    if (books[i].is_borrowed == false) {
        cout << "Book is available!" << endl;
    }
    else {
        cout << "Book is borrowed!" << endl;
    }
    cout << "--------------------" << endl;
}

void borrowBook(int i) {

    books[i].is_borrowed = true;

    if (books[i].is_borrowed == true) {
        cout << "You have borrowed the book. Congratulations!" << endl;
        cout << "--------------------\n" << endl;
    }
}

void returnBook(int i) {

    books[i].is_borrowed = false;

    if (books[i].is_borrowed == false) {
        cout << "You have returned the book. Congratulations!" << endl;
        cout << "--------------------\n" << endl;
    }
}


void createBook() {

    for (int i = 0; i < n; i++) {
        cout << "Enter the book title: ";
        cin.ignore(1, '\n');
        getline(cin, books[i].name);

        cout << "Enter the publication year: ";
        cin >> books[i].year;

        cout << "Enter the author's name: ";
        cin.ignore(1, '\n');
        getline(cin, books[i].author_name);

        cout << "Enter ID: ";
        cin >> books[i].id;

        getBookStatus(i);
    }
}


void manageBook() {

    int free_or_busy;
    int yes_now;
    string AllName;

    cout << "Return a book - enter '1', borrow a book - enter '2': ";
    cin >> yes_now;

    switch (yes_now)
    {
    case 1:
        cout << "Enter the title of the book you want to return: ";
        cin >> AllName;
        cout << "\nIf the title does not match, no information will be displayed!!!\n" << endl;
        cout << "--------------------" << endl;

        for (int i = 0; i < n; i++) {
            if (AllName == books[i].name) {
                cout << "Book: " << books[i].name << endl;
                cout << "Publication year: " << books[i].year << endl;
                cout << "Author's name: " << books[i].author_name << endl;
                cout << "ID: " << books[i].id << endl;
                getBookStatus(i);
                returnBook(i);
            }

        }
        break;

    case 2:
        cout << "Do you want to borrow a book for reading?" << endl;
        cout << "If yes, enter '1'. If no, enter '0': ";
        cin >> free_or_busy;

        switch (free_or_busy)
        {
        case 1:

            cout << "Enter the title of the book you want to borrow: ";
            cin >> AllName;
            cout << "\nIf the title does not match, no information will be displayed!!!\n" << endl;
            cout << "--------------------" << endl;

            for (int i = 0; i < n; i++) {
                if (AllName == books[i].name) {
                    cout << "Book: " << books[i].name << endl;
                    cout << "Publication year: " << books[i].year << endl;
                    cout << "Author's name: " << books[i].author_name << endl;
                    cout << "ID: " << books[i].id << endl;
                    getBookStatus(i);
                    borrowBook(i);
                }

            }
            break;

        case 0:
            cout << "The book remains available." << endl;
            break;

        default:
            cout << "Invalid value!" << endl;
            break;
        }
        break;

    default:
        cout << "Invalid value!" << endl;
        break;
    }

}


void assortment()
{
    cout << "Our collection: " << endl;
    cout << "1) List of books" << endl;
    cout << "2) Search by book title" << endl;
    cout << "3) Search by author name" << endl;
    cout << "4) Search by ID/series\n" << endl;

    cout << "Choose an option from 1-4: " << endl;

    int choice;
    int last_res = 0;
    int id_s;
    string AllName;

    cin >> choice;

    switch (choice) {
    case 1:
        for (int i = 0; i < n; i++) {
            cout << "Book: " << books[i].name << endl;
            cout << "Publication year: " << books[i].year << endl;
            cout << "Author's name: " << books[i].author_name << endl;
            cout << "ID: " << books[i].id << endl;
            getBookStatus(i);
        }

        break;

    case 2:
        cout << "Enter the book title: ";
        cin >> AllName;
        cout << "\nIf the title does not match, no information will be displayed!!!\n" << endl;
        cout << "--------------------" << endl;

        for (int i = 0; i < n; i++) {
            if (AllName == books[i].name) {
                cout << "Book: " << books[i].name << endl;
                cout << "Publication year: " << books[i].year << endl;
                cout << "Author's name: " << books[i].author_name << endl;
                cout << "ID: " << books[i].id << endl;
                getBookStatus(i);
            }

        }

        break;

    case 3:
        cout << "Enter the author's name: ";
        cin >> AllName;
        cout << "\nIf the name does not match, no information will be displayed!!!\n" << endl;
        cout << "--------------------" << endl;


        for (int i = 0; i < n; i++) {
            if (AllName == books[i].author_name) {
                cout << "Book: " << books[i].name << endl;
                cout << "Publication year: " << books[i].year << endl;
                cout << "Author's name: " << books[i].author_name << endl;
                cout << "ID: " << books[i].id << endl;
                getBookStatus(i);
            }
        }
        break;

    case 4:
        cout << "Enter ID/series: ";
        cin >> id_s;
        cout << "\nIf the ID does not match, no information will be displayed!!!\n" << endl;
        cout << "--------------------" << endl;


        for (int i = 0; i < n; i++) {
            if (id_s == books[i].id) {
                cout << "Book: " << books[i].name << endl;
                cout << "Publication year: " << books[i].year << endl;
                cout << "Author's name: " << books[i].author_name << endl;
                cout << "ID: " << books[i].id << endl;
                getBookStatus(i);
            }
        }
        break;


    default:
        cout << "Invalid value!" << endl;

    }

}

void mainMenu() {

    int switch_on;

    while (true) {
        cout << "Menu: " << endl;
        cout << "1) Book collection" << endl;
        cout << "2) Return/Borrow a book" << endl;
        cout << "3) Exit" << endl;
        cout << "--------------------" << endl;

        cout << "Enter an option from 1-3: ";
        cin >> switch_on;

        // Book management - calling manageBook
        switch (switch_on)
        {
            // Restarting code - function
        case 1:
            assortment();
            mainMenu();
            break;

            // True or False book
        case 2:
            cout << "Do you want to return/borrow a book?" << endl;
            manageBook();
            break;

            // Break code
        case 3:
            return;
            break;

        default:
            mainMenu();
            break;
        }
    }
}


int main() {

    setlocale(LC_ALL, "ukr");

    cout << "------------------------" << endl;
    cout << "Welcome to the Library!" << endl;
    cout << "------------------------\n" << endl;

    createBook();
    assortment();
    mainMenu();

    return 0;
}