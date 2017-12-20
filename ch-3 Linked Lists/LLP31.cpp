/*
Problem 31: Merge two sorted list
Time Complexity: O(m+n) m,n are length of two list
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
  * Method to merge two sorted linked list
**/
sll* mergeList (sll *head1, sll *head2) {
  if (!head1) return head2;
  if (!head2) return head1;
  sll *result = NULL;
  if (head1->data < head2->data) {
    result = head1;
    result->next = mergeList (head1->next, head2);
  } else {
    result = head2;
    result->next = mergeList (head1, head2->next);
  }
  return result;
}
int main (void) {
  sll *head = NULL;
  insert (&head, 3, 1);
  insert (&head, 2, 1);
  insert (&head, 1, 1);

  cout<<"\nList 1:";
  printSll (head);
  sll *head2 = NULL;
  insert (&head2, 6, 1);
  insert (&head2, 5, 1);
  insert (&head2, 4, 1);

  cout<<"\nList 2:";
  printSll (head2);
  sll *head3 = mergeList (head, head2);
  cout<<"\nMerge Sorted List:";
  printSll (head3);
  cout<<endl;
  return 0;
}
