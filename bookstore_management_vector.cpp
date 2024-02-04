/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */


#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Book{
    string bookName;
    int bookID;
    float price;
    int bookQty;
};

int menu(){
  int choice;
  cout << "::BOOK STORE PROGRAM MENU::\n";
  cout << "1. Register book\n";
  cout << "2. Display book record\n";
  cout << "3. Delete book\n";
  cout << "4. Update Book\n";
  cout << "5. Exit program\n"<<endl;
  cout << "Enter choice: ";
  cin >> choice;
  return choice;
}

void registerBook(vector<Book>&Record,Book data){
    cout<<"Book name: ";
    cin.ignore();
    getline(cin,data.bookName);
    cout<<"Book ID: ";
    cin>>data.bookID;
    cout<<"Book price: ";
    cin>>data.price;
    cout<<"Book quantity: ";
    cin>>data.bookQty;
    cout<<endl;
    Record.push_back(data);
    cout<<"Book successfully added."<<endl<<endl;
}

void displayBook(vector<Book>&Record){
    int option;
    cout<<"1. Display details of individual book\n2. Display details of all books\n "<<endl;;
    cout<<"Choose an option:";
    cin>>option;
    cout<<endl;
    if(option==1){
        int id;
        cout<<"Enter book ID to search for: ";
        cin>>id;
        cout<<endl;
        for(int i=0;i<Record.size();i++){
            if(Record[i].bookID==id){
                cout << "Book Name: " << Record[i].bookName << endl;
                cout << "Book ID: " << Record[i].bookID << endl;
                cout << "Book Price: " << Record[i].price << endl;
                cout << "Book Quantity: " << Record[i].bookQty << endl;
                cout<<endl;
                return;
            }
        }
        cout << "Book not found.\n";
        cout<<endl;
    }else if (option==2){
        for(int i=0;i<Record.size();i++){
            cout << "Details of Book ["<<i<<"]"<<endl;
            cout << "Book Name: " << Record[i].bookName << endl;
            cout << "Book ID: " << Record[i].bookID << endl;
            cout << "Book Price: " << Record[i].price << endl;
            cout << "Book Quantity: " << Record[i].bookQty << endl;
            cout<<endl;
        }
    }else{
        cout<<endl;
        cout<<"Invalid option.\n";
    }
}

void deleteBook(vector<Book>&Record){
    int id;
    cout<<endl;
    cout<<"Enter book id to be deleted: ";
    cin>>id;
    cout<<endl;
    vector<Book>::iterator x;
    for(x=Record.begin();x<Record.end();x++){
        if(x->bookID==id){
            Record.erase(x);
            cout<<endl;
            cout<<"Book with id "<<id<<" is deleted.\n"<<endl;
            cout<<endl;
            return;
        }
    }
    cout<<"Book id: "<<id<<" not found.\n"<<endl;
}

void updateBook(vector<Book>&Record){
    int id,choice;
    cout<<endl;
    cout<<"Enter book id you want to update: ";
    cin>>id;
    for(int i=0;i<Record.size();i++){
        if(Record[i].bookID==id){
            cout<<endl;
            cout<<"1.Update book name.\n2.Update book price.\n3.Update book quantity.\n";
            cout<<endl;
            cout<<"Enter update option:";
            cin>>choice;
            cout<<endl;
            
            switch(choice){
                case 1:
                    cout<<"Enter updated book name: ";
                    cin>>Record[i].bookName;
                    break;
                case 2:
                    cout<<"Enter updated book price: ";
                    cin>>Record[i].price;
                    break;
                case 3:
                    cout<<"Enter updated book quantity: ";
                    cin>>Record[i].bookQty;
                    break;
                default:
                    cout << "Invalid option." << endl;
                    break;    
            }
        }else{
            cout<<"Book id: "<<id<<" not found.\n";
            return;
        }
    }
    cout<<endl;
    cout << "Book details updated successfully.\n";
}

int main(){
  vector<Book>Record;
  Book data;
  int choice; 

  do {
    choice = menu();
    switch (choice) {
      case 1: 
        registerBook(Record,data);//call function registerBook() and push the data to vector. 
            break;
          case 2: 
            displayBook(Record);//call function displayBook()
        break;
      case 3: 
        deleteBook(Record);//call function deleteBook()
        break;
      case 4: 
        updateBook(Record);//call function updateBook()
        break;
    }
  } while (choice != 5);
  return 0;
}
