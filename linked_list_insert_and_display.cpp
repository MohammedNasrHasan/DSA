/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */

/*Linked Lists**/

#include <iostream>

using namespace std;
struct data {
    int no;
    data*next;
};

data *createNode(){// we rtuen up to the return value 
    // create a storage/node
    data*n=new data();
    cout<<"Enter a number";
    cin>>n->no;
    n->next=NULL;
    return n;//return address
    
}

void insertNode(data **head){//recive address
    data *p=*head;//dumby pointer p 
    data*n =createNode();
    //insert new node to linked list 
    
    //1. check if linked list is empty
    if(*head==NULL)
        *head=n;
    //2. insertion at the end/begining/middle
    else{
        while(p->next!=NULL)
            p = p->next;
        p->next = n;
    }
}
void display(data *h){
    
    //display all nodes
    for(;h!=NULL;h=h->next)
        cout<<h->no;
    
}
int main()
{
    data*head=NULL;char choice;
    do{
        
        insertNode(&head);
        cout<<"Add new data :";
        cin>>choice;
        
    }while (choice=='y');
    display(head);// passing address of fist node
    cout<<"Hello World";

    return 0;
}
