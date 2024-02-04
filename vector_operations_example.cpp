/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void display(vector<int>rec){
      vector<int> ::iterator i;
      for(i=rec.begin();i!=rec.end();i++)
      cout<<*i;
      
}

int main() {
	vector<int> rec {2,4,6,8};
	//declare suitable variables

    cout << "\nOriginal list:"<<endl;
	display(rec);
	int no;
	cout<<"\n\nEnter three additional data:";
	for (int i=1;i<4;i++) {
	    cin>>no;
	    rec.insert(rec.begin(),no);
	    
	}
    cout << "List after adding three data:";
	display(rec);
    
    cout << "\n\nChange the 3rd data to 9";
    vector<int>::iterator insert;
    insert=rec.begin();
    advance(insert,2);
    *insert=9;
    cout << "\nList after update the 3rd data:";
    display(rec);
    
    cout << "\n\nSort the data in acsending order";
    sort(rec.begin(),rec.end());// sorting in vectors we need to specifiy the bound and no rec.sort
    cout << "\nList after the data are sorted:";
    display(rec);
    
    cout << "\n\nDelete data 4";
    rec.erase(rec.begin()+3);// we can use remove in vectors we have to advance and erase
    cout << "\nList after data 4 is deleted:";
    display(rec);
    
    cout << "\n\nDelete the first three data";
    vector<int> :: iterator del,delr;
    del=rec.begin();
    delr=rec.begin();
    advance(delr,3);   // first iterator is advanced 
    rec.erase(del,delr);// then we delete from begin till designated desination 
    cout << "\nList after the first three data are deleted:";
    display(rec);
    return 0;
}