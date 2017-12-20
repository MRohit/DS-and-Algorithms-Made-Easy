/*
Problem 27: Find middle of a linked list
Time Complexity: O(n) using one scan
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
Method to find middle node using one scan
**/
void findMiddleNode (sll *head) {
  sll *temp1 = head, *temp2 = head;
  int flag = 1;
  while (temp1->next != NULL) {
    if (flag == 1) {
      temp1 = temp1->next;
      flag = 0;
    } else if (flag == 0) {
      temp1 = temp1->next;
      temp2 = temp2->next;
      flag = 1;
    }

  }
  cout<<"\nMiddle node:"<<temp2->data<<endl;
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
  insert (&head, 9, 3);

  cout<<"\nList 1:";
  printSll (head);

  findMiddleNode (head);
  cout<<endl;
  return 0;
}
