/*Data Structure & Algorithms 
Mohammed Nasr Anes Hasan
  */
#include<iostream>

using namespace std;
struct Data
{
  float mark;
  Data *next;
};

void
push (Data * &head, float mark)
{
  Data *n = new Data;
  n->mark = mark;
  n->next = head;
  head = n;
}

void
grading (Data * head)
{
  int totalPass = 0, totalFail = 0;
  Data *temp = head;
  cout << "::Grading::" << endl;
  while (temp != NULL)
    {
      if (temp->mark >= 50)
	{
	  cout << temp->mark << " : Pass" << endl;
	  totalPass++;
	}

      else
	{
	  cout << temp->mark << " : Fail" << endl;
	  totalFail++;
	}
      temp = temp->next;
    }
  cout << "Total Pass: " << totalPass << endl;
  cout << "Total Fail: " << totalFail << endl;
}

void
pop (Data * &head)
{
  Data *temp = head;
  while (temp != NULL)
    {
      Data *current = temp;
      temp = temp->next;
      delete current;
    }
  head = NULL;
  cout << endl;
  cout << "Removing all marks...." << endl;
  cout << "[Result] All marks have been deleted" << endl;
}

int
main ()
{
  Data *head = NULL;
  int size;
  float mark;


  cout << "Enter total data to insert: ";
  cin >> size;
  for (int i = 1; i <= size; i++)
    {
      cout << "Enter mark : ";
      cin >> mark;
      cout << endl;

      push (head, mark);
    }
  grading (head);		//   to display pass/fail 

  pop (head);			//  to remove 

  cout << "\nEnd of program";
  return 0;
}
