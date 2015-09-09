/*
  Program to sort numbers in ascending order using maxheaps
*/

#include<bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &a, int i,int siz)      // 0(logn)
{
  int val=i,flag=0, leftc=2*i+1, rightc=2*(i+1);
      if(a[i]<a[leftc] && leftc<siz)
          { val=leftc; flag=1;}

      if(a[i]<a[rightc] &&rightc<siz)
          { val=rightc; flag=1;}

      if(rightc<siz &&leftc<siz && flag)
         val=a[leftc]>a[rightc]?leftc:rightc;

   if(val!=i)
   {
     swap(a[i],a[val]);
     maxHeapify(a,val,siz);
   }
}


void buildMaxHeap(vector<int> &a)
{
  for(int i=a.size()/2-1;i>=0;i--)
    maxHeapify(a,i,a.size());
}

int extractMin(vector<int> &a)
 {  int  maximum=a[0];
     swap(a[0],a[a.size()-1]);
     a.pop_back();
     maxHeapify(a,0,a.size());
     return maximum;
 }

 int findMin(vector<int> a)
  {  if(a.size())
     return a[0];
     else return -1;
  }

 void heapsort(vector<int> &a)
 {
   for(int i=a.size();i>=2;--i) // n times , therefore nlog(n)
   {
       swap(a[0],a[i-1]);
       maxHeapify(a,0,i-1);       //o(log(n))
   }
 }

int main()
 {
  cout<<"Enter the total number of elements:\n";
  int t;
  cin>>t;
  vector<int> a(t);
  cout<<"Enter the elements you want to sort:\n";
  for(int i=0;i<t;i++)
    cin>>a[i];
  buildMaxHeap(a);  //complexity is o(n) actually even if it seems nlogn
  heapsort(a);
  cout<<"\nSorted sequence: ";
  for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
  cout<<endl;

  cout<<"Minimum elemted is now extracted : ";
  cout<<extractMin(a)<<endl;

  heapsort(a);
  cout<<"Current sequence:\n";
  for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
    cout<<endl;

 return 0;
 }

/* Explainantion of complexity of buildMaxHeap()
   0*n/2 + 1*n/4 + 2*n/8 + 3*n/16+........ < n
   becoz n/4 elements can go down 1 level atmost
         n/8 can go 2
         aans so on
*/

