#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    Book(int id, string title, string author)
        : id(id), title(title), author(author), isIssued(false) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIsIssued() const { return isIssued; }

    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    void displayBookInfo() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author
             << ", " << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully." << endl;
    }

    void removeBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                cout << "Book removed successfully." << endl;
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

    void issueBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id) {
                if (!book.getIsIssued()) {
                    book.issueBook();
                    cout << "Book issued successfully." << endl;
                } else {
                    cout << "Book is already issued." << endl;
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id) {
                if (book.getIsIssued()) {
                    book.returnBook();
                    cout << "Book returned successfully." << endl;
                } else {
                    cout << "Book was not issued." << endl;
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }
        for (const auto& book : books) {
            book.displayBookInfo();
        }
    }
};


int main() {
    Library library;
    int choice, id;
    string title, author;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore(); // To clear the input buffer
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(Book(id, title, author));
                break;
            case 2:
                cout << "Enter Book ID to remove: ";
                cin >> id;
                library.removeBook(id);
                break;
            case 3:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                library.issueBook(id);
                break;
            case 4:
                cout << "Enter Book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;
            case 5:
                library.displayAllBooks();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
