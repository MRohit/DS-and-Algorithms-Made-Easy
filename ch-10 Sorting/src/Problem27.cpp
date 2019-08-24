#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct sll{
   int data;
   struct sll *next;
}sll;

sll *insert (sll *head, int data) {
    sll *newNode = NULL , *temp = NULL,*temp2 = NULL;
    newNode = (sll*) malloc (sizeof(sll));
    if (!newNode)   return NULL;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        temp = head;
        while (temp->next != NULL) {
          temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }
    return head;

}
void printsll(sll*head){
   sll *temp = head;
   while(temp != NULL) {
      cout<<temp->data<<"->";
      temp = temp->next;
   }
   cout<<endl;
}
sll *mergeSortedList (sll *head1, sll *head2) {

  sll *temp = (sll*) malloc(sizeof(sll));
  sll *head = temp;
  while (head1 != NULL && head2 != NULL) {
    if (head1->data <= head->data) {
      temp->next = head1;
      temp = temp->next;
      head1 = head1->next;
    } else {
      temp->next = head2;
      temp = temp->next;
      head2 = head2->next;
    }
  }
  if (head1 != NULL)
    temp->next = head1;
  if (head2 != NULL)
    temp->next = head2;

  temp = head;
  head = head->next;
  return head;
}
void frontBackSplit (sll *source, sll **front, sll **back) {
  sll *slow = source;
  sll *fast = source->next;
  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      fast = fast->next;
      slow = slow->next;
    }
  }
  *front = source;
  *back = slow->next;
  slow->next = NULL;
}
void mergeSort (sll **head) {
  sll *headref = *head;
  if (*head == NULL || (*head)->next == NULL)
    return;
  sll *a, *b;

  frontBackSplit (headref, &a, &b);

  mergeSort(&a);
  mergeSort (&b);

  (*head) = mergeSortedList (a, b);
}
int main (void) {
  sll *head1 = NULL, *head2 = NULL;
  for (int i=5;i>=0;i--) {
    head1= insert(head1, i);

  }

  cout<<"\nAfter performing merge sort on linked list:";
  mergeSort (&head1);
  printsll(head1);

  return 0;
}
