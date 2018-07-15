/*
  Problem 71: Count number unique BSTs possible given n
  Time Complexity: O(n)
**/

#include<iostream>
#include<stdlib.h>
#include<queue>
#include<vector>
#include<stack>
#include<unordered_set>
//#include<bits/stdc++>
using namespace std;

/*
defining the structure
**/
typedef struct Tree {

  int data;
  struct Tree *left, *right;
}BSTree;

BSTree* initializeNode () {
  BSTree *root = (BSTree*) malloc (sizeof (BSTree));
  if (!root)  return NULL;
  root->left = root->right = NULL;
  return root;
}

int countUniqueBSTs (int n) {
  if (n <= 1) {
    return 1;
  } else {
    int sum = 0;
    int left, right, root;
    for (root = 1; root <= n; ++root) {
      left = countUniqueBSTs (root - 1);
      right = countUniqueBSTs (n - root);

      sum+= left*right;
    }
    return sum;
  }

}
void preorder (BSTree *root) {
  if (root) {
    cout<<root->data<<" ";
    preorder (root->left);
    preorder (root->right);
  }
}
vector<BSTree *> createUniqueBSTs (int start, int end) {
  vector<BSTree *> list;
  if (start > end) {
    list.push_back (NULL);
    return list;
  }
  // iterating through all the values from start to end
  for (int i = start; i <= end; i++) {
    // create leftsubtree
    vector<BSTree *> leftSubtree = createUniqueBSTs (start, i - 1);

    // create right subtree
    vector<BSTree *> rightSubtree = createUniqueBSTs (i + 1, end);

    // looping through all the left and right subtrees and connect with ith root
    for (int j = 0; j < leftSubtree.size(); j++) {
      BSTree *left = leftSubtree [j];
      for (int k = 0; k < rightSubtree.size(); k++) {
        BSTree *right = rightSubtree[k];
        BSTree *node = initializeNode ();
        node->data = i;
        node->left = left;
        node->right = right;
        list.push_back (node);
      }
    }
  }
  return list;
}
int main (void) {
  int n = 3;
  cout<<"\nUnique trees possible:"<<countUniqueBSTs (n);

  cout<<"\nCreating all unique trees:";
  vector<BSTree*> list = createUniqueBSTs (1, n);
  cout<<"\nPreorder traversal of all unique trees:";
  for (int i = 0; i < list.size(); i++)
    {
        preorder(list[i]);
        cout << endl;
    }
  cout<<endl;
  return 0;
}
