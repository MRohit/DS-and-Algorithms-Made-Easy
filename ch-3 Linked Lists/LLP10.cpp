/*
  * Problem 9: Check if linked list is NULL terminated or not using Floyd Algorithm
  * Time Complexity: O(n)
  * Space Complexity: O(1)
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

void insert (sll **head,  int data, int pos) {
  sll *newNode, *temp = *head, *curr, *temp2 = *head;
  int k = 1;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (pos == 1) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  while ((temp != NULL) && (k < pos - 1)) {
    temp = temp->next;
    k++;
  }
  if(data == 9)
    newNode->next = temp2->next->next;
  else
    newNode->next = temp->next;
  temp->next = newNode;
  return;
}

/*
Method to print all nodes
**/
void printsll (sll **head) {
  sll *temp = *head;
  while (temp != NULL) {
    cout<<temp->data<<"->";
    temp = temp->next;
  }

}


/*
Method to detect if Linked list has a loop using Floyd Algorithm
**/
void findLoop (sll **head) {
  sll *slow = *head, *fast = *head;
  int flag = 0;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    cout<<"\nIt's a snail";
  else
    cout<<"\nIt's a snake";
}

int main (void) {
  sll *head = NULL;
  insert (&head, 1, 1);
  insert (&head, 2, 2);
  insert (&head, 3, 3);
  insert (&head, 4, 4);
  insert (&head, 5, 5);
  insert (&head, 6, 6);
  insert (&head, 7, 7);
  insert (&head, 8, 8);
  insert (&head, 9, 9);
  //printsll(&head);

  findLoop (&head);
  return 0;
}
