#include<iostream>
using namespace std;

void towerOfHanoi (int n, char from, char to, char temp) {
  if(n==1) {
    cout <<"Disk:"<<n<<" moved from peg:"<<from<<" to peg:"<<to<<endl;
    return;
  }

  towerOfHanoi (n-1, from, temp, to);

  cout <<"Disk:"<<n<<" moved from peg:"<<from<<" to peg:"<<to<<endl;
  towerOfHanoi (n-1, temp, to, from);
}

int main (void) {
  towerOfHanoi(3,'A','B','C');
  return 0;
}
