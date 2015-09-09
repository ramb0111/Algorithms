/*
  A program to find the peak which means a number which is not smaller
  than its negihbours
  i.e. any number which satisfies
  this condition for index i <N  , Number[i-1]<=Number[i]=>Number[i+1];
  brute force is O(n) but this problem is also possible to solve in log(n)
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
   int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
   cin>>a[i];
   /*complexity(log(n))*/
  int beg=1,end=n-2,mid;  // excluding first an last value

 /*All 3 possible cases are considered*/
   if(a[beg]<a[beg-1])    // if decreasing order
      {cout<<"peak is "<<a[beg-1]; return 0;}

    if(a[end]<a[end+1])   // if increasing order
      {cout<<"peak is "<<a[end+1]; return 0;}

  while(beg<=end)    // if random
  {
    mid=(beg+end)/2;
    if(a[mid]>=a[mid-1] && a[mid]>=a[mid+1])
      {cout<<"peak is "<<a[mid]; return 0;}
     else if(a[mid]<a[mid-1])
        end=mid-1;
    else
        beg=mid+1;

  }
 }
