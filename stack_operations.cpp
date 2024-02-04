/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */

#include <iostream>
#include <stack>
using namespace std;

struct person{
    int idNo;
    float weight;
};

void display(stack<person>rec){
    int i = 1;
    while(!rec.empty()){
        cout<<"Record "<<i<<" - Id no:"<<rec.top().idNo;
        cout<<", Weight: "<<rec.top().weight<<endl;
        rec.pop();
    }
}

void deletion(stack<person> *rec){
    int i = 1;
    while(!rec->empty()){
        cout<<"Record "<<i<<" - Id no:"<<rec->top().idNo;
        cout<<", Weight: "<<rec->top().weight<<endl;
        rec->pop();
    }
}


int main()
{
    stack<person>record;
    person data;
    int i = 1; 
    
    for(;i<=3;i++){
        cout<<"Record "<<i<<":"<<endl;
        cout<<"Enter id :";
        cin>>data.idNo;
        cout<<"Enter weight :";
        cin>>data.weight;
        record.push(data);
    }
    
    cout<<"Total data in stack :"<<record.size()<<endl;
    
    cout<<"\n::Details of record::"<<endl;
    display(record);
    
    cout<<"\n::Deletion process::"<<endl;
    deletion(&record);
    
    if(record.empty())
        cout<<"End of stack record";

    return 0;
}
