#include<iostream>
using namespace std;

int locByBinarySearch(int n,int key,int a[])
{ int mid, beg=0,end=n;
  if(a[n]>key)
  {
     while(beg<end)
     {   mid=(beg+end)/2;
         if(a[mid]<=key && a[mid+1]>=key)
         {
            return mid+1;
         }
         else if(a[mid]<key)
            beg=mid;
         else if(a[mid]>key)
            end=mid;
     }
  }
  else return n+1;
}


int main()
 {
 cout<<"Enter the total number of elements:\n";
 int n;
  cin>>n;
  int a[n];
  cout<<"Enter the elements you want to sort:\n";
  for(int i=0;i<n;++i)
   cin>>a[i];

 for(int i=1;i<n;i++)
 {
     int key=a[i];
    int i1=locByBinarySearch(i-1,key,a),j=i;

   while(i>i1)
    {
      a[i]=a[i-1];
      --i;
    }
    a[i1]=key;
    i=j;
 }
cout<<"\nSorted sequence: ";
 for(int i=0;i<n;++i)
   cout<<a[i]<<" ";
 return 0;
 }
