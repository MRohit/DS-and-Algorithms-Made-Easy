/*
Problem 23: Find merging point of two Linked list using Stack
Time Complexity: O(max(m,n)), m and n are length of two linked lists
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
Method to find common node from where the merging starts
**/
void findCommonPoint (sll *head1, sll *head2) {
  // step1: get the length of both the lists
  int len1 = 0, len2 = 0;
  sll *temp1 = head1, *temp2 = head2;
  while (temp1 != NULL) {
    len1 ++;
    temp1 = temp1->next;
  }

  while (temp2 != NULL) {
    len2 ++;
    temp2 = temp2->next;
  }

  // step2: take the difference
  int diff = 0;
  if (len1 < len2) {
    diff = len2 - len1;
    temp1 = head2;
    temp2 = head1;
  } else {
    diff = len1 - len2;
    temp1 = head1;
    temp2 = head2;
  }
  // step3: traverse the greatest list upto the difference
  for (int i = 0; i < diff; i ++) {
    temp1 = temp1->next;
  }
  // step4: compare data and print the first merging point
  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data == temp2->data) {
      cout<<"\nMerging point:"<<temp1->data<<endl;
      break;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
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


  sll *head2 = NULL;
  insert (&head2, 20, 1);
  insert (&head2, 21, 1);
  insert (&head2, 22, 1);

  // creating a common node by merging them at some random point.
  head2->next->next->next = head->next->next->next->next->next;

  cout<<"\nList 1:";
  printSll (head);
  cout<<"\nList 2:";
  printSll (head2);

  findCommonPoint (head, head2);
  cout<<endl;
  return 0;
}
