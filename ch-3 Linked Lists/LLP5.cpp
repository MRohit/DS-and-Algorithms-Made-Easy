/*
  * Problem 5: Finding Nth node from the last
  * Time Complexity: O(n), in this we're doing one scan
  * Space Complexity: O(1)  since we're not creating any hash table
**/

#include<iostream>
#include<stdlib.h>
using namespace std;
/*
defining the structure
**/
typedef struct sll{
  int data;
  struct sll *next;
}sll;

/*
Method to insert the data into linked list
**/
void insert (sll **head, int data, int pos){
  sll *newNode = NULL, *temp = *head, *curr = NULL;
  int k = 1;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (pos == 1) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  while ((temp != NULL) && (k < pos - 1)){
    temp = temp->next;
    k ++;
  }

  newNode->next = temp->next;
  temp->next = newNode;
  return;
}

/*
Method to print all nodes
**/
void printsll (sll **head){
  sll *temp = *head;
  while (temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }

}

/*
Method to find nth node from last in one scan.
**/
void findNode (sll **head, int pos){
  sll *temp = *head, *pnth = NULL;
  int count = 1;
  for (count = 1; count < pos; count++){
    if (temp)
      temp = temp->next;
  }
  while (temp) {
    if(pnth == NULL)
      pnth = *head;
    else
      pnth = pnth->next;
    temp = temp->next;
  }
  if (pnth)
    cout<<"\nFound-Data:"<<pnth->data<<endl;
}
int main (void) {
  sll *head = NULL;

  insert (&head, 1, 1);
  insert (&head, 2, 1);
  insert (&head, 3, 2);
  printsll (&head);

  //finding nth node from a Linked List
  findNode (&head, 1);
  return 0;
}
