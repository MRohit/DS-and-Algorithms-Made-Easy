/*
Problem 51: Separate even odd numbers in linked list
Time Complexity: O (n)
Space Complexity: O(1)
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
Method to insert data into linked list
**/
void insert (sll **head, int data) {
  sll *temp = *head, *newNode = NULL;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL)
    *head = newNode;
  else {
    while (temp->next != NULL)
	   temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
  }
}
void print (sll **head) {
  sll *temp = *head;
  while (temp != NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}

/*
Method to Separate even and odd in linked list
**/
void getEvenOdd (sll *head) {
  sll *evenHead = NULL, *evenEnd = NULL, *oddHead = NULL, *oddEnd = NULL;
  if (head == NULL)
    return;

  while (head != NULL) {
    if (head->data % 2 == 0) {
      if (evenHead == NULL) {
        evenHead = evenEnd = head;
      } else {
        evenEnd->next = head;
        evenEnd = head;
      }
    } else {
      if (oddHead == NULL) {
        oddHead = oddEnd = head;
      } else {
        oddEnd->next = head;
        oddEnd = head;
      }
    }

    head = head->next;
  }
  if (evenHead == NULL || oddHead == NULL)
    return;

  evenEnd->next = oddHead;
  oddEnd->next = NULL;
  head = evenHead;
  cout<<"\nAfter even odd separation:";
  print (&head);
}
int main (void) {
  sll *head = NULL;
  insert (&head, 1);
  insert (&head, 2);
  insert (&head, 3);
  insert (&head, 4);
  print (&head);

  getEvenOdd (head);
  cout<<endl;
  return 0;
}
