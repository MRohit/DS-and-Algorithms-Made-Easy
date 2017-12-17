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
typedef struct sll{
  int data;
  struct sll *next;
}sll;

/*
Method to insert data into linked list based on their position
**/
void insert(sll **head, int data,int pos){
  sll *newNode,*temp=*head,*curr;
  int k=1;
  newNode=(sll*)malloc(sizeof(sll));
  newNode->data=data;
  newNode->next=NULL;
  if(pos==1){
    newNode->next=*head;
    *head=newNode;
    return;
  }

  while((temp!=NULL) && (k<pos-1)){
    temp=temp->next;
    k++;
  }

  newNode->next=temp->next;
  temp->next=newNode;
  return;
}

/*
Print all nodes of linked list
**/
void printsll(sll **head){
  sll *temp=*head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<endl;
}

/*
finding nth node of a linked list.
Time Complexity: O(n);
**/
int findNodeEnd(sll **head,int pos) {
  // base condition
  if (*head == NULL)
    return 0;
  sll *temp = *head;
  temp = temp->next;
  int count = findNodeEnd (&temp,pos);
  if (count == pos){
    cout<<"\nNth:"<<pos<<" node from end:"<<temp->data;
    count++;
  }

  return ++count;
}
int main (void){
  sll *head=NULL;
  insert(&head,1,1);
  insert(&head,2,1);
  insert(&head,3,2);
  insert(&head,4,1);
  insert(&head,5,2);
  insert(&head,6,1);
  insert(&head,7,2);
  printsll(&head);

  //finding nth node from the end of a Linked List
  int d=findNodeEnd(&head,2);
  cout<<endl;
  return 0;
}
