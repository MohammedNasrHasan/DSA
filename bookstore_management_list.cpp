/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */

#include <iostream>
#include <list>
#include <string>

using namespace std;

//Question 3(1)
struct Book {
    string bookName;
    int bookID;
    float price;
    int bookQty;
};

//Question 3(2)
int menu() {
    int choice;
    cout << ":: BOOK STORE PROGRAM MENU ::\n";
    cout << "1. Register book\n";
    cout << "2. Display book record\n";
    cout << "3. Delete book\n";
    cout << "4. Update Book\n";
    cout << "5. Exit program\n";
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

void registerBook(Book& data) {
    cout << "Enter book ID: ";
    cin >> data.bookID;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, data.bookName);
    cout << "Enter book price: ";
    cin >> data.price;
    cout << "Enter book quantity: ";
    cin >> data.bookQty;
}


//Question 3(3)
void displayBook(list<Book>& books, int option) {
    if (option == 1) {
        int input;
        cout << "Enter ID of the book you are looking for: ";
        cin >> input;
        for (const auto& book : books) {
            if (book.bookID == input) {
                cout << "Book Name: " << book.bookName << endl;
                cout << "Book ID: " << book.bookID << endl;
                cout << "Book Price: " << book.price << endl;
                cout << "Book Quantity: " << book.bookQty << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    } else if (option == 2) {
        cout << ":: Book Record ::" << endl;
        for (const auto& book : books) {
            cout << "Book Name: " << book.bookName << endl;
            cout << "Book ID: " << book.bookID << endl;
            cout << "Book Price: " << book.price << endl;
            cout << "Book Quantity: " << book.bookQty << endl << endl;
        }
    } else {
        cout << "Invalid option." << endl;
    }
}

void deleteBook(list<Book>& books) {
    int delid;
    cout << ":: Book Deletion ::" << endl;
    cout << "Enter the ID of the of book you want to delete: ";
    cin >> delid;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->bookID == delid) {
            cout << "Deleting book: " << it->bookName << endl;
            it = books.erase(it);
            cout << "Book deleted." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void updateBook(list<Book>& books) {
    int input;
    cout << "Enter the ID of the book you want to update: ";
    cin >> input;
    for (auto& book : books) {
        if (book.bookID == input) {
            int choice;
            cout << "What would you like to update?\n";
            cout << "1. Book Name\n";
            cout << "2. Book Price\n";
            cout << "3. Book Quantity\n";
            cin >> input;
            switch (input) {
                case 1:
                    cout << "Enter new book name: ";
                    cin >> book.bookName;
                    cout << "Book name updated.\n";
                    break;
                case 2:
                    cout << "Enter new book price: ";
                    cin >> book.price;
                    cout << "Book price updated.\n";
                    break;
                case 3:
                    cout << "Enter new book quantity: ";
                    cin >> book.bookQty;
                    cout << "Book quantity updated.\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}


int main() {
    list<Book> Record;
    int choice;
    Book data = {};

    do {
        choice = menu();

        switch (choice) {
            case 1:
                {
                    data = {}; //initialize the Book data
                    registerBook(data);
                    Record.push_back(data);
                    break;
                }
            case 2:
                {
                    int option;
                    cout << "Enter 1 to search by ID, 2 to display all records: ";
                    cin >> option;
                    displayBook(Record, option);
                    break;
                }
            case 3:
                deleteBook(Record);
                break;
            case 4:
                updateBook(Record);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
