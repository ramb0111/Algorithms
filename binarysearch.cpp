#include<bits/stdc++.h>
using namespace std;
int main()
 {
  cout<<"Enter the size of the array:\n";
  int n;
  cin>>n;
  int a[n],val;
  cout<<"Enter the numbers in ascending order\n";
  for(int i=0;i<n;i++)
   cin>>a[i];
 cout<<"Enter the searching element:\n";
   cin>>val;
  int beg=0,end=n-1,mid,f=0;
 while(beg<=end)
  {
    mid=(beg+end)/2;

    if(a[mid]==val)
      {f=1;break;}

    if(a[mid]<val)
    {
        beg=mid+1;
    }
    else if(a[mid]>val)
        end=mid-1;
  }

  if(f)
    cout<<"Found at index :"<<mid+1<<"  (starting with 1th index)"<<endl;
  else cout<<"Not Found";

  return 0;
 }
