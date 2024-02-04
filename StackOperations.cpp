/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */
#include <iostream>
#include <stack>
using namespace std;

void display(stack<int>rec){
    while(!rec.empty()){
        cout<<"Top value : "<<rec.top()<<endl;
        rec.pop();
    }
}

void deletes(stack<int> *rec){
    while(!rec->empty()){
        cout<<"Top value : "<<rec->top()<<endl;
        rec->pop();
    }
}

int main()
{
    stack<int>rec;
    int i = 1,no;
    
    for(;i<=5;i++){
        cout<<"Enter value "<<i<<" : ";
        cin>>no;
        rec.push(no);
    }
    cout<<"Total data in stack : "<<rec.size()<<endl;
    
    cout<<"\n::Content of stack::"<<endl;
    display(rec);
    
    cout<<"\n::Deletion process::"<<endl;
    deletes(&rec);
    
    if(rec.empty())
        cout<<"Stack is empty";

    return 0;
}
