/*
Problem 32: To reverse list in pairs
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
} sll;

/*
Method to insert data into linked list
**/
void insert (sll **head, int data) {
  sll *temp = *head, *newNode  =  NULL;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  } else {
    while (temp->next != NULL)
      temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return;
  }
}
void print (sll **head) {
  sll *temp = *head;
  while (temp != NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }
}
/*
Method to reverse list in pairs using recursion
**/
sll* reverseRecursion (sll *head) {
  if (!head || head->next == NULL)  return head;
  else {
    // reverse first pair
    sll *temp = NULL;
    temp = head->next;
    head->next = temp->next;
    temp->next = head;
    // keep head at first element in pair to point to next pairs second element
    head = temp;

    // reverse remaining pairs
    head->next->next = reverseRecursion (head->next->next);

    return head;
  }

}

/*
Method to reverse list in pairs using non-recursion
**/
void withoutRecursion (sll **head) {
  sll *curr = *head, *temp = NULL, *temp2 = NULL;
  while (curr != NULL && curr->next != NULL) {
    // add link from previous pair to next pair
    if (temp != NULL)
      temp->next->next = curr->next;

    // reverse current pairs
    temp = curr->next;
    curr->next = temp->next;
    temp->next = curr;

    // store the header
    if(temp2 == NULL)
      temp2 = temp;

    // go to next pair
    curr = curr->next;
  }
  *head = temp2;
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
  print (&head);
  head = reverseRecursion (head);
  cout<<"\nAfter pair switching:";
  print (&head);
  sll *head2 = NULL;
  insert (&head2, 11);
  insert (&head2, 22);
  insert (&head2, 33);
  insert (&head2, 44);
  insert (&head2, 55);
  insert (&head2, 66);
  insert (&head2, 77);
  insert (&head2, 88);
  withoutRecursion (&head2);
  cout<<"\nAfter without recursion:";
  print (&head2);

  cout<<endl;
  return 0;
}
