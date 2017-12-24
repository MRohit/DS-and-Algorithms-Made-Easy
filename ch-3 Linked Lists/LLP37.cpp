/*
Problem 37: Check if linked list Palidrome
Time Complexity: O(n)
Space Complexity: O(1)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct sll {
  int data;
  struct sll *next;
} sll;

/*
Method to insert data into linked list
**/
void insert(sll **head, int data) {
  sll *temp = *head, *newNode = NULL;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  } else {
    while (temp->next != NULL) {
      temp = temp->next;
    }
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
Method to reverse a linked list
**/
sll* reverse (sll *head2) {

}

/*
Method to check if linked list is Palidrome or not
**/
void isPalindrome (sll **head) {

}

int main (void) {
  sll *head = NULL;
  insert (&head, 1);
  insert (&head, 2);
  insert (&head, 3);
  insert (&head, 4);
  insert (&head, 5);
  insert (&head, 4);
  insert (&head, 3);
  insert (&head, 8);
  insert (&head, 1);
  print (&head);
  isPalindrome (&head);
  print (&head);
  cout<<endl;
  return 0;
}
