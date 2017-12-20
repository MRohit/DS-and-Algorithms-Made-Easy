/*
Problem 30: Merge two sorted list using non-recursive approach
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
  * Method to merge two sorted linked list using non recursive approach
**/
sll* mergeList (sll *head1, sll *head2) {
  sll *temp = NULL, *resultList = NULL;
  resultList = (sll*) malloc (sizeof(sll));
  if (!resultList)  return NULL;

  temp = resultList;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data <= head2->data) {
      resultList->next = head1;
      head1 = head1->next;
      resultList = resultList->next;
    } else {
      resultList->next = head2;
      head2 = head2->next;
      resultList = resultList->next;
    }
  }

  if (head1 != NULL)
    resultList->next = head1;
  else
    resultList->next = head2;
  resultList = temp->next;
  free (temp);
  return resultList;
}
int main (void) {
  sll *head = NULL;
  insert (&head, 3, 1);
  insert (&head, 2, 1);
  insert (&head, 1, 1);

  cout<<"\nList 1:";
  printSll (head);
  sll *head2 = NULL;
  insert (&head2, 8, 1);
  insert (&head2, 7, 1);
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
