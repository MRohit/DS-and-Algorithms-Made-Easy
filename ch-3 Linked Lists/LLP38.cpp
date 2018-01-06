/*
Problem 38: Reverse linked list in k blocks
Time Complexity: O(n)
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
  if (*head == NULL) {
    *head = newNode;
    return;

  } else {
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
Method to reverse a linked list in given size of pairs
Time Complexity O(n)
**/
sll *reverse(sll *head, int k) {
  sll *next = NULL, *curr = head, *temp = NULL;
  int i = 0;
  while (curr != NULL && i < k) {
    next = curr->next;
    curr->next = temp;
    temp = curr;
    curr = next;
    i++;
  }
  if (next != NULL)
    head->next = reverse (next,k);
  return temp;
}

sll *nonRecursiveReverse (sll *head, int k) {
  sll *next = NULL, *curr = head, *temp = NULL, *temp2 = head;
  int i = 0;
  do {
    i = 0;
    curr = temp2;
    while (curr != NULL && i < k) {
      next = curr->next;
      curr->next = temp;
      temp = curr;
      curr = next;
    }
    temp2 = temp;
  } while (curr != NULL);

  return temp2;
}
int main (void) {
  sll *head = NULL, *head2, *list2 = NULL;

  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);
  insert(&head, 6);
  insert(&head, 7);
  insert(&head, 8);
  insert(&head, 9);
  insert(&head, 10);
  insert(&head, 11);
  insert(&head, 12);
  print(&head);

  cout<<"\nAfter Reverse:";
  head2 = reverse (head, 3);
  print (&head2);

  insert(&list2, 11);
  insert(&list2, 12);
  insert(&list2, 13);
  insert(&list2, 14);
  insert(&list2, 15);
  insert(&list2, 16);
  insert(&list2, 17);
  insert(&list2, 18);
  insert(&list2, 19);
  insert(&list2, 20);
  insert(&list2, 21);
  insert(&list2, 22);
  cout<<"\nAfter Reverse (Non Recursive):";
  head2 = nonRecursiveReverse (list2, 3);
  print (&head2);

}
