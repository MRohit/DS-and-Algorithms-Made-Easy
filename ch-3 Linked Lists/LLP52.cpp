/*
Problem 52: Add two numbers represented using Linked List
Time Complexity: O (m+n)
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
  sll *temp = *head, *newNode = NULL;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL)
    *head = newNode;
  else {
    while (temp->next != NULL)
	   temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
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
Method to create a Node
**/
sll *createNode (int sum) {
  sll *temp = (sll*) malloc (sizeof(sll));
  temp->next = NULL;
  temp->data = sum;
  return temp;
}

/*
Method to Separate even and odd in linked list
**/
void addTwoNumbers (sll *n1, sll *n2) {
  /*
  Input:
    First List: 7->5->9->4->6  // represents number 64957
    Second List: 8->4 //  represents number 48
  Output
    Resultant list: 5->0->0->5->6  // represents number 65005

  */
  sll *result = NULL, *prev = NULL, *temp = NULL;
  int carry = 0, sum = 0;
  while (n1 != NULL || n2 != NULL) {
    // 1. calculate sum = carry + (n1 + n2)
    sum = carry + (n1? n1->data : 0) + (n2? n2->data : 0);
    // 2. check if sum is greater than 10 and store it in carry accordingly
    carry =  (sum >= 10) ? 1 : 0;

    // 3. update the sum if it is greater than 10
    sum = sum % 10;

    // 4. create a new node;
    temp = createNode (sum);

    if (result == NULL) {
      result = temp;
    } else {
      prev->next = temp;
    }

    prev = temp;

    if (n1) n1 = n1->next;
    if (n2) n2 = n2->next;
  }

  if (carry > 0) {
    temp->next = createNode (carry);
  }
  cout<<"\nAddition is:";
  print (&result);
}
int main (void) {
  sll *n1 = NULL, *n2 = NULL;
  insert (&n1, 7);
  insert (&n1, 5);
  insert (&n1, 9);
  insert (&n1, 4);
  insert (&n1, 6);
  cout<<"\nFirst Number:";
  print (&n1);
  insert (&n2, 8);
  insert (&n2, 4);

  cout<<"\nSecond Number:";
  print (&n2);

  addTwoNumbers (n1, n2);
  cout<<endl;
  return 0;
}
