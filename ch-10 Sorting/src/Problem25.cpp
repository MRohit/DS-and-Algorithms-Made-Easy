#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct sll{
   int data;
   struct sll *next;
}sll;

sll *insert (sll *head, int data) {
    sll *newNode = NULL , *temp = NULL,*temp2 = NULL;
    newNode = (sll*) malloc (sizeof(sll));
    if (!newNode)   return NULL;

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else if(head->data > data) {
      newNode->next = head;
      head = newNode;
    } else {
      temp = head;
      while (temp != NULL && temp->data < data) {
        temp2 = temp;
        temp = temp->next;
      }
      temp2->next = newNode;
      newNode->next = temp;
    }
    return head;

}
void printsll(sll*head){
   sll *temp = head;
   while(temp != NULL) {
      cout<<temp->data<<"->";
      temp = temp->next;
   }
   cout<<endl;
}
sll *mergeSortedList (sll *head1, sll*head2) {
  sll *result = NULL;
  if (head1 == NULL)
    return head2;
  else if (head2 == NULL)
    return head1;

  if (head1->data <= head2->data) {
    result = head1;
    result->next = mergeSortedList(head1->next, head2);
  } else {
    result = head2;
    result->next = mergeSortedList (head1,head2->next);
  }
  return result;
}
sll *newNode (int data) {
  sll *temp = (sll*) malloc(sizeof(sll));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

sll *mergeKSortedList (sll *arr[], int last) {
  while (last != 0) {
    int i = 0, j = last;
    while (i < j) {
      arr[i] = mergeSortedList (arr[i], arr[j]);
      i++;j--;
      if (i >= j)
        last = j;
    }
  }
  return arr[0];
}
int main (void) {
  sll *head1 = NULL, *head2 = NULL;
  for (int i=5;i>=0;i--) {
    head1= insert(head1, i);

  }
  for (int i=10;i>=6;i--) {
    head2 = insert(head2, i);

  }
  head1 = mergeSortedList(head1,head2);
  cout<<"\nAfter merging two sorted linked list:";
  printsll(head1);

  int k =4, n = 3;
  sll *arr[k];
  arr[0] = newNode(1);
  arr[0]->next = newNode(4);
  arr[0]->next->next = newNode(7);
  arr[0]->next->next->next = newNode(10);
  arr[0]->next->next->next->next = newNode(13);

  arr[1] = newNode(2);
  arr[1]->next = newNode(5);
  arr[1]->next->next = newNode(8);
  arr[1]->next->next->next = newNode(11);
  arr[1]->next->next->next->next = newNode(14);

  arr[2] = newNode(3);
  arr[2]->next = newNode(6);
  arr[2]->next->next = newNode(9);
  arr[2]->next->next->next = newNode(12);
  arr[2]->next->next->next->next = newNode(15);

  arr[3] = newNode(0);
  arr[3]->next = newNode(16);
  arr[3]->next->next = newNode(17);
  arr[3]->next->next->next = newNode(18);
  arr[3]->next->next->next->next = newNode(19);
  sll *head = mergeKSortedList (arr, k - 1);
  cout<<"\nAfter merging K sorted linked list:";
  printsll(head);
  return 0;
}
