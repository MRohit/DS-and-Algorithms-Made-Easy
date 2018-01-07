/*
Problem 47: Finding a fractional node in a linked list
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
  sll *newNode = NULL, *temp = *head;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  while (temp->next != NULL)
    temp = temp->next;
  newNode->next = temp->next;
  temp->next = newNode;
}
void print (sll **head) {
  sll *temp = *head;
  while (temp != NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}

/*
Method to find fractional node in linked list
**/
void fractionalNode (sll **head, int k) {

  sll *fractional = NULL, *temp = *head;
  if(temp == NULL)
    return;
  int i = 0;
  while (temp != NULL) {
    if (i % k == 0) {
      if (fractional == NULL) {
        fractional = temp;
      } else {
        fractional = fractional->next;
      }

    }
    temp = temp->next;
    i++;
  }
  if (fractional != NULL)
    cout<<"\nFractional Node:"<<fractional->data<<endl;
  else
    cout<<"\nFractional Node doesn't exist"<<endl;
}

int main (void) {
  sll *head = NULL;
  insert (&head, 1);
  insert (&head, 2);
  insert (&head, 3);
  insert (&head, 4);
  insert (&head, 5);
  insert (&head, 6);
  insert (&head, 7);
  insert (&head, 8);
  insert (&head, 9);
  print (&head);
  fractionalNode (&head, 4);
  cout<<endl;
  return 0;
}
