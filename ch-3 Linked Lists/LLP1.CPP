/*
Problem 1: Implementing Stack using Linked List
Time Complexity: O(1) except for DeleteStack: O(n)
Space Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
defining the structure
**/
typedef struct stl {
  int data;
  struct stl *next;
} stll;

/*
Method to push element into stack
Time Complexity: O(1)
**/
void push (stll **head, int data) {
  stll *newNode = NULL, *temp = NULL;
  newNode = (stll*) malloc(sizeof(stll));
  if(!newNode)  return;
  newNode->data = data;
  newNode->next = NULL;

  if(*head == NULL)
    *head = newNode;
  else {
    newNode->next = *head;
    *head = newNode;
  }
}

/*
Method to print all elements of stack
Time Complexity: O(n)
**/
void print (stll **head) {
  stll *temp=*head;
  while(temp != NULL) {
    cout<<temp->data<<endl;
    temp = temp->next;
  }
}
/*
Method to get top element of stack
Time Complexity: O(1)
**/
int getTop (stll **head) {
  if(*head == NULL) {
    cout<<"\nStack Empty, returning 0";
    return 0;
  } else {
    return (*head)->data;
  }
}
int isEmpty (stll **head) {
  if(*head == NULL)
    return 1;
  else
    return 0;
}
/*
Method to pop element of stack
Time Complexity: O(1)
**/
int pop (stll **head) {
  if(isEmpty(&(*head))) {
    return 0;
  } else {
    stll *temp = *head;
    *head = temp->next;
    int data = temp->data;
    free(temp);
    return data;
  }
}

/*
Method to delete all elements of stack
Time Complexity: O(n)
**/
void deleteStack (stll **head) {
  stll *temp = *head, *temp2=NULL;
  while(temp != NULL) {
    temp2 = temp;
    temp = temp->next;
    free (temp2);
  }
}


int main (void) {
  stll *head = NULL;
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);
  cout<<"\nStack contents:";
  print(&head);
  cout<<"\nTop:"<<getTop(&head);
  cout<<"\nPop element:"<<pop(&head);
  cout<<"\nPop element:"<<pop(&head);
  cout<<"\nPop element:"<<pop(&head);
  cout<<"\nTop:"<<getTop(&head);
  return 0;
 // print(&head);
}
