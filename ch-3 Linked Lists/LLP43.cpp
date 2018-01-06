/*
Problem 43: Separate even and odd data from linked list
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
  sll *temp = *head, *newNode;
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
  sll *temp4 = *head, *temp2 = *head, temp3;
  while (temp4 != NULL) {
    cout<<temp4->data<<"->";
    temp2 = temp4;
    temp4 = temp4->next;
  }
}

void separateList (sll **head) {
  sll *even = NULL, *odd = NULL, *temp = *head;
  while (temp != NULL) {
    if (temp->data % 2 == 0) {
      insert (&even, temp->data);
    } else {
      insert (&odd, temp->data);
    }
    temp = temp->next;
  }
  temp = even;
  while (temp->next != NULL)  temp = temp->next;
  temp->next = odd;
  cout<<"\nAfter rearranging even and odd:";
  print (&even);
  cout<<endl;
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
  insert (&head, 10);

  print(&head);
  separateList(&head);
  return 0;
}
