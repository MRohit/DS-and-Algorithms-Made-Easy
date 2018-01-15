/*
Problem 21: Find merging point of two Linked list using Stack
Time Complexity: O(m+n), m and n are length of two linked lists
Space Complexity: O(m+n)  for maintaining two stacks
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

typedef struct st {
  int cap, top;
  struct sll **arr;
} st;

/*
Stack utility methods
**/
st* initializeStack (int cap) {
  st *s = (st*) malloc (sizeof (st));
  if(!s)  return NULL;
  s->cap = cap;
  s->top = -1;
  s->arr = (sll**) malloc (sizeof(sll) * cap);
  if(!s->arr) return NULL;
  return s;
}

int isEmpty (st *s) {
  return s->top == -1;
}

int isFull (st *s) {
  return s->top == s->cap - 1;
}

void push (st *s, sll *data) {
  if (isFull (s)) {
    cout<<"\n Stack is full"<<endl;

  } else {
    s->arr[++s->top] = data;
  }
}

sll* pop (st *s) {
  if (isEmpty (s)) {
    cout <<"\nStack is empty"<<endl;
    return NULL;
  }
  return s->arr[s->top--];

}

sll *getTop (st *s) {
  return s->arr[s->top];
}
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
  st *s1 = initializeStack (10);
  st *s2 = initializeStack (10);

  sll *temp1 = head1;
  while (temp1 != NULL) {
    push (s1,temp1);
    temp1 = temp1->next;
  }

  sll *temp2 = head2;
  while (temp2 != NULL) {
    push (s2,temp2);
    temp2 = temp2->next;
  }

  int flag = 0;
  sll *top1 = NULL, *top2 = NULL;
  while(getTop(s1)->data==getTop(s2)->data){
      top1=pop(s1);
      top2=pop(s2);

  }
  cout<<"\nIntersection node:"<<top1->data;

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
