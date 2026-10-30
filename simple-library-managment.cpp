
#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool borrowed;
};

Book books[100];
int count = 0;


void addBook() {
    cout << "\nEnter Book ID: ";
    cin >> books[count].id;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, books[count].title);

    cout << "Enter Author Name: ";
    getline(cin, books[count].author);

    books[count].borrowed = false;

    count++;

    cout << "\nBook added successfully!\n";
}


void displayBooks() {
    if (count == 0) {
        cout << "\nNo books available!\n";
        return;
    }

    cout << "\n===== BOOK LIST =====\n";

    for (int i = 0; i < count; i++) {
        cout << "\nBook ID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;
        cout << "\nAuthor: " << books[i].author;

        if (books[i].borrowed == false) {
            cout << "\nStatus: Available\n";
        }
        else {
            cout << "\nStatus: Borrowed\n";
        }
    }
}


void borrowBook() {
    int id;

    cout << "\nEnter Book ID to borrow: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {

            if (books[i].borrowed == false) {
                books[i].borrowed = true;
                cout << "\nBook borrowed successfully!\n";
            }
            else {
                cout << "\nThis book is already borrowed!\n";
            }

            return;
        }
    }

    cout << "\nBook not found!\n";
}

void returnBook() {
    int id;

    cout << "\nEnter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {

            if (books[i].borrowed == true) {
                books[i].borrowed = false;
                cout << "\nBook returned successfully!\n";
            }
            else {
                cout << "\nThis book was not borrowed!\n";
            }

            return;
        }
    }

    cout << "\nBook not found!\n";
}


int main() {
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                borrowBook();
                break;

            case 3:
                returnBook();
                break;

            case 4:
                displayBooks();
                break;

            case 5:
                cout << "\nExiting the system. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
