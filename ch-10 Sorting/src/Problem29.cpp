#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 100000
void result(int a[],int n){
   for(int i=0;i<n;++i)
      cout<<a[i]<<" ";
}

void countingSort(int a[],int temp[],int k,int n){

   int count[k];
   for (int i=0;i<k;i++) {
     count[i] = 0;
   }
   for (int i=0;i<n;i++) {
     count[a[i]]++;
   }
   for (int i=0;i<k;i++) {
     count[i] = count[i] + count[i-1];
   }
   for (int j = n-1;j>=0;j--) {
     temp[count[a[j]]] = a[j];
     count[a[j]]--;
   }
   result(temp,n);
}
int main(){
   int a[MAX];
   int n=1000;
   int temp[MAX],max=255,min=0;
  // a[0]=1;a[1]=2;
//   int randNum;
   for(int i=0;i<n;++i){
     /* if(max-i+1 !=0)
         randNum=(rand()%(max-i+1)+i);*/
      if(max==0)
         max=255;
      a[i]=max;
      max--;
   }

   countingSort(a,temp,256,n);
   return 0;
}
