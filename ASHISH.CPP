#include "iostream.h"
#include "conio.h"
#include "string.h"
struct Programe2
{
 char name[15];
 struct Programe2 *next;
};
typedef Programe2 node;
node *New,*head = NULL,*ptr;
void create(char *n) //Function to create node and link
{
 New = new node;
 strcpy(New -> name,n);
 if(head == NULL)
  {
  head = New;
   head -> next = head;
   ptr = head;
  }
 else
  {
    ptr -> next = New;
    New -> next = head;
    ptr = New;
   }
}
node* remove(char *n) //Function to delete a node
{
 node *temp = head,*deleted;
 while(strcmp(temp -> next -> name,n) != 0)
   temp = temp -> next;

 deleted = temp -> next;
 temp -> next = temp -> next -> next;
 return deleted; //return deleted node
}
int main()
{
 create(""); //Create first node with empty contents to represent end or Start of list
 int m,n,i,j;
 char nme[15],sname[15];
 do
 {
  cout << "How many KIDs are there? ";
  cin >> m;
  if(m <= 0)
   cout << "\nPlease choose number greater than " << m << endl;
 }while(m <= 0);

 do
 {
  cout << "\nEnter N = "; //Scan N
  cin >> n;
  if(n <= 0||n>=m)
  cout << "\nPlease pick the number 1 to m-1" << m;
 }while(n <= 0||n>=m);

 for(i = 0;i < m;i++) //Scan Kids Name
  {
   cout << "\nEnter Name : ";
   cin >> nme;
  create(nme); //Create a list of Kids
  }
 node *temp = head,*nd;
 cout << endl << endl;
 for(int k = 0;k < m;k++)
  {
   j = 0;
   for(i = 1;i <= n;i++) //Loop from 1 to n
   {
    temp = temp -> next; //Move to next node
    j++;
    if(strcmp(temp -> name,"") == 0) //Ignore empty node
     {
      j--;
      i--;
     }

    if(j == n) //If node is found
     {
      nd = remove(temp -> name); //Remove node
      if(k != m-1) //If more than one node
       cout << "Eliminated Kid : " << nd -> name << endl;
      else
	 cout << "\nThe Winner Kid Is" << nd -> name << endl;
      break;
     }
  }
 }
 getch();
 return 0;
}