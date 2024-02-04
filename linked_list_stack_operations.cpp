/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */
#include <iostream>
using namespace std;

struct data{
    int no;
    data *next;
};

void push(data **head, int no){
    //node creation
    data *n = new data();
    n->no = no;
    n->next = NULL;
    
    //node insertion at the beginning
    n->next = *head;
    *head = n;
}

void display(data *h){
    while(h!=NULL){
        cout<<"Top value : "<<h->no<<endl;
        h = h->next;
    }
}

void deletes(data **head){
    while(*head!=NULL){
        data *p = *head;
        cout<<"Top value : "<<(*head)->no<<endl;
        *head = (*head)->next;
        free(p);
    }
}

int main()
{
    data *head = NULL;
    int i = 1,no;
    
    for(;i<=5;i++){
        cout<<"Enter value "<<i<<" : ";
        cin>>no;
        push(&head,no);
    }
    cout<<"Total data in stack : "<<i-1<<endl;
    
    cout<<"\n::Content of stack::"<<endl;
    display(head);
    
    cout<<"\n::Deletion process::"<<endl;
    deletes(&head);
    
    if(head==NULL)
        cout<<"Stack is empty";

    return 0;
}
