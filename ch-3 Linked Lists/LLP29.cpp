/*
Problem 29: Check if list is even or odd
Time Complexity: O(n/2) = O(n)
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
}sll;

/*
Method to insert the data into linked list
**/
void insert (sll **head, int data, int pos){
  sll *newNode = NULL, *temp=*head, *curr = NULL;
  int k = 1;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (pos == 1){
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

void printSll (sll *head) {
  sll *temp = head;
  while(temp!= NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}

/*
Method to display linked list from end
**/
void isEvenOdd (sll *head) {
  while (head && head->next) {
    head = head->next->next;
  }
  if (!head) {
    cout<<"\nOdd list";
  } else {
    cout<<"\nEven list";
  }
}
int main (void) {
  sll *head = NULL;
  insert (&head, 1, 1);
  insert (&head, 2, 1);
  insert (&head, 3, 1);
  insert (&head, 4, 1);
  insert (&head, 5, 1);
  insert (&head, 8, 2);
  insert (&head, 9, 3);
  insert (&head, 10, 3);
  insert (&head, 10, 3);

  cout<<"\nList 1:";
  printSll (head);
  isEvenOdd (head);
  cout<<endl;
  return 0;
}
