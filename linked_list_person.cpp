
/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */


#include <iostream>
using namespace std;

class Person {
    public:
    int age;
    Person *next;
    //missing code
};


Person *createNode() {
    Person *n = new Person();
    cout<<"Enter age: ";
    cin>>n->age;
    n->next=NULL;
    return n;
    //missing code
}


void insertNode(Person **head /*suitable parameter*/) {    
    Person *n,*p;//p=null
    char choice;
    //variable declaration
    do{
        n = createNode();
        //insert first node into linked list
        if(*head==NULL)
            *head=n;
        //missing code
        //insert second node onwards at the end of linked list
        else {
            p=*head;
            while(p->next!=NULL)
                p=p->next;
                p->next = n;
                //missing code      
        }
        cout<<"Press [y] for new record:";
        cin>>choice;
    }while(choice=='y');
}

void display(Person *h/*suitable parameter*/) {
    cout<<"All records  : ";
    for(;h!=NULL;h=h->next)
        cout<<h->age<<" ";//missing code
}

void analysis(Person *h) {
    if (h == NULL) {
        cout << "The linked list is empty." << endl;
        return;
    }
    int min_age = h->age;
    int max_age = h->age;
    for (; h != NULL; h = h->next) {
        if (h->age < min_age)
            min_age = h->age;
        if (h->age > max_age)
            max_age = h->age;
    }
    cout << "\n\nThe youngest age is: " << min_age << endl;
    cout << "\nThe oldest age is: " << max_age << endl;
}

int main() {
    Person *head = NULL;
  insertNode(&head);
  cout <<"\n**List of existing record"<<endl;
  display(head);//call display()
  analysis(head);//call analysis()
  return 0;
}