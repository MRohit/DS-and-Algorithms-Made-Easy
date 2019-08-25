#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAX 100000

void convertArraytoSawToothWave(int ar[], int n) {
  for(int i=1;i <n;i+=2) {
    if (i+1 < n) {
      int temp = ar[i];
      ar[i] = ar[i+1];
      ar[i+1] = temp;
    }
  }

}
int main(){
  int ar1[] = {0,-6,9,13,10,-1,8,12,54,14,-5};

    int n = sizeof(ar1)/sizeof(ar1[0]);
    sort(ar1,ar1+n);
    convertArraytoSawToothWave(ar1,  n);

    cout << "After converting  Array: ";
    for (int i=0; i<n; i++)
        cout << ar1[i] << " ";

   cout<<endl;
   return 0;
}
