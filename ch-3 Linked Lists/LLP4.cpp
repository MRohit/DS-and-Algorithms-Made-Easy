/*
Problem 4: Finding Nth node from the last
Time Complexity: O(n), we're doing two scans both of O(n)
Space Complexity: O(1)  since we're not creating any hash table
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

/*
Print all nodes in the linked list
**/
void printsll (sll **head){
  sll *temp = *head;
  while (temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }

}

/*
Method to find nth node
**/
void findNode (sll **head,int pos){
  sll *temp = *head,*pnth = NULL;
  int totalNodes = 0, k = 1;

  // Count all nodes present in linked list
  while (temp != NULL){
    temp = temp->next;
    totalNodes ++;
  }
  cout<<"\nTotal Nodes:"<<totalNodes<<endl;

  temp = *head;
  // get the nth node
  while ((temp!=NULL) && (k<=totalNodes)) {
     if (k == (totalNodes - pos + 1)) {
      cout<<"\nNode found:Data->"<<temp->data<<endl;
      break;
     }

     temp = temp->next;
     k ++;
  }
}

int main (void){
  sll *head = NULL;

  insert (&head, 1, 1);
  insert (&head, 2, 1);
  insert (&head, 3, 2);
  printsll (&head);

  //finding nth node from a Linked List
  findNode (&head, 2);
  return 0;
}
