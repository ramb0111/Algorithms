#include<bits/stdc++.h>
using namespace std;
int main()
 {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;++i)
   cin>>a[i];
    for(int j=1;j<n;++j)
      {
          int key=a[j],j1=j;
          while(key<a[j-1] && j>0) // to check sorted array with the  key element
          {
              a[j]=a[j-1]; //to move numbers left to right like pack of cards
              j--;
          }
          a[j]=key;
          j=j1;
      }
      for(int k=0;k<n;++k)
            cout<<a[k];

   return 0;
 }
