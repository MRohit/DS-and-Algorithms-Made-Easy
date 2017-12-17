/*
  Doubly Linked List Program with following operations:
  1. Insertion  O(n)
  2. Deletion   O(n)
  3. Printing   O(n)
**/
#include <iostream>
#include <stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct dll{
  int data;
  struct dll *next, *prev;
} dll;

/*
  method to insert a node in double linked list
**/
void insert (dll **head, int data, int pos) {
  dll *temp1 = NULL, *temp2 = NULL, *newNode = NULL;
  newNode = (dll*) malloc (sizeof(dll));
  if(!newNode) {
    return;
  }
  newNode->data = data;
  newNode->next = newNode->prev = NULL;

  if(pos == 1) {
    newNode->next = *head;
    if(*head) {
      (*head)->prev = newNode;
    }
    *head = newNode;
    return;
  }
  temp1 = *head;
  int position = 1;
  while (temp1->next != NULL && position < pos-1) {
    position ++;
    temp1 = temp1->next;
  }

  newNode->next = temp1->next;
  newNode->prev = temp1;
  if (temp1->next)
    temp1->next->prev = newNode;
  temp1->next = newNode;
}

/*
  method to delete a node from double linked list
**/
void deleteNode (dll **head, int pos) {
  dll *temp1 = NULL, *temp2 = NULL;
  if(pos == 1) {
    temp1 = *head;
    *head = (*head) ->next;
    free (temp1);
    return;
  }
  int position = 1;
  temp1 = *head;
  while(temp1->next != NULL && position < pos - 1){
    position++;
    temp1 = temp1->next;
  }
  if(position != pos-1){
    cout << "Position doesn't exist:" << pos<< '\n';
    return;
  }
  temp2 = temp1->prev;
  temp2->next = temp1->next;
  // if it's not last node
  if (temp1->next) {
    temp1->next->prev = temp2;
  }
  free(temp1);
}

/*
  method to print double linked list
**/
void printdll (dll **head) {
  dll *temp;
  temp = *head;
  while (temp != NULL) {
    printf ("<-%d->", temp->data);
    temp = temp->next;
  }
  cout<<endl;
}


int main (void) {
  dll *head  =  NULL;
  insert (&head, 3, 1);
  insert (&head, 2, 1);
  insert (&head, 1, 1);
  insert (&head, 5, 1);

  insert (&head, 6, 3);
  insert (&head, 7, 2);
  insert (&head, 8, 7);

  printdll (&head);
  deleteNode (&head, 3);

  cout<<"\nafter deleting 3rd position\n";
  printdll (&head);

  return 0;
}
