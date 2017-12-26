/*
Problem 37: Check if linked list Palidrome
Time Complexity: O(n)
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
} sll;

/*
Method to insert data into linked list
**/
void insert(sll **head, int data) {
  sll *temp = *head, *newNode = NULL;
  newNode = (sll*) malloc (sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if (*head == NULL) {
    *head = newNode;
    return;
  } else {
    while (temp->next != NULL) {
      temp = temp->next;
    }
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
Method to reverse a linked list
**/
sll* reverse (sll *head2) {
  sll *curr = head2, *next = NULL, *temp = NULL;
  while (curr != NULL) {
    next = curr->next;
    curr->next = temp;
    temp = curr;
    curr = next;
  }
  return temp;
}

/*
Method to check if linked list is Palidrome or not
**/
void isPalindrome (sll **head) {
  sll *temp = NULL, *middle = *head, *fast = *head;
  // 1. Get middle element
  int cnt = 1;
  while (fast != NULL) {
    if(cnt == 1) {
      fast = fast->next;
      cnt = 0;
    } else if (cnt == 0){
      middle = middle->next;
      fast = fast->next;
      cnt = 1;
    }
  }
  cout<<"\nMiddle Node:"<<middle->data<<endl;
  // 2. Reverse second half of linked list
  sll *secondHalfReverseList = reverse (middle);

  // 3. Compare first and second half and get the result
  int flag = 0;
  sll *first = *head, *second = secondHalfReverseList;
  while (first->next != middle && second != NULL) {
    if(first->data != second->data) {
      flag = 1;
      cout<<"\nLinked list is not palindrome"<<endl;
      return;
    }
    first = first->next;
    second = second->next;
  }
  cout<<"\nLinked list is palindrome"<<endl;
}

int main (void) {
  sll *head = NULL;
  insert (&head, 1);
  insert (&head, 2);
  insert (&head, 3);
  insert (&head, 4);
  insert (&head, 5);
  insert (&head, 4);
  insert (&head, 3);
  insert (&head, 2);
  insert (&head, 1);
  print (&head);
  isPalindrome (&head);
  cout<<endl;
  return 0;
}
