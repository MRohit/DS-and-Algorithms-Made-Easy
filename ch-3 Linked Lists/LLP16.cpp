/*
  * Problem 16: Reverse a singly linked list
  * Time Complexity: O(n)
  * Space Complexity: O(1)
**/

#include <iostream>
#include <stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct sll {
  int data;
  struct sll *next;
} sll;

/*
Method to insert the data into sorted linked list
**/
void insertIntoSortedLL (sll **head, int data) {
  sll *temp = *head, *newNode = NULL, *temp2 = *head;

  newNode = (sll*) malloc (sizeof(sll));
  if(!newNode)  return;
  newNode->data = data;
  newNode->next = NULL;

  if(*head == NULL) {
    *head = newNode;
    return;
  }
  if (temp->data > data) {
    newNode->next = temp;
    *head = newNode;
    return;
  }

  while (temp != NULL && temp->data < data) {
    temp2 = temp;
    temp = temp->next;
  }
  newNode->next = temp;
  temp2->next = newNode;

}

void printSortedLL (sll **head) {
  sll *temp = *head;
  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
}

/*
Non Recursive function to reverse a linked list
**/
sll* reverseLinkedList (sll *head) {
  sll *current = head, *next = NULL, *temp = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = temp;
    temp = current;
    current = next;
  }
  return temp;
}
int main (void) {
  sll *head = NULL;
  insertIntoSortedLL (&head, 8);
  insertIntoSortedLL (&head, 7);
  insertIntoSortedLL (&head, 6);
  insertIntoSortedLL (&head, 5);
  insertIntoSortedLL (&head, 4);
  insertIntoSortedLL (&head, 3);
  insertIntoSortedLL (&head, 2);
  insertIntoSortedLL (&head, 1);
  insertIntoSortedLL (&head, 15);
  insertIntoSortedLL (&head, 13);
  insertIntoSortedLL (&head, 11);

  cout<<"\nlinked list:";
  printSortedLL (&head);
  cout<<"\nReverse linked list:";
  head = reverseLinkedList (head);
  printSortedLL (&head);
  cout<<endl;
}
