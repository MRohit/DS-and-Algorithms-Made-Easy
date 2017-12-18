/*
  * Problem 6: Check if linked list is NULL terminated or not (using Brute Force)
  * Time Complexity:
  * Space Complexity:
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
void insert (sll **head,  int data,  int pos){
  sll *newNode  =  NULL,  *temp  =  *head,  *curr  =  NULL,  *temp2  =  *head;
  int k = 1;
  newNode = (sll*)malloc(sizeof(sll));
  newNode->data = data;
  newNode->next = NULL;
  if(pos == 1){
    newNode->next = *head;
    *head = newNode;
    return;
  }

  while ((temp != NULL) && (k < pos - 1)) {
    temp = temp->next;
    k ++;
  }
  if (data == 9)
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
Method to check if linked list is NULL terminated or not
**/
void findLoop (sll **head){
  sll *temp = *head, *loopStart = *head, *temp2 = NULL;
  loopStart = loopStart->next->next->next;
  temp2 = loopStart;
  int flag = 0;
  while (temp->next) {
     while (loopStart !=  temp2){

       if(temp->next  ==  temp2->next) {
	        flag = 1;
	         break;
       }
       temp2 = temp2->next;

     }
     if (flag == 1) {
       printf("\nLoop found\n");
       break;
     }
  }

}
int main (void) {
  sll *head = NULL;

  insert(&head, 1, 1);
  insert(&head, 2, 2);
  insert(&head, 3, 3);
  insert(&head, 4, 4);
  insert(&head, 5, 5);
  insert(&head, 6, 6);
  insert(&head, 7, 7);
  insert(&head, 8, 8);
  insert(&head, 9, 9);
  //printsll(&head);
  findLoop(&head);
  //finding nth node from a Linked List
//  findNode(&head, 1);
  return 0;
}
