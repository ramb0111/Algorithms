#include<bits/stdc++.h>
using namespace std;

int root(int a[],int i)
{
  while(i!=a[i])
  {
   i=a[a[i]];
  }
  return i;
}

void setunion(int ar[],int a,int b,int siz[])
{
 int roota=root(ar,a);
  int rootb=root(ar,b);
 if(siz[roota]<siz[rootb])
  {
   siz[rootb]+=siz[roota];
   ar[roota]=ar[rootb];
  }
 else
 {
 siz[roota]+=siz[rootb];
   ar[rootb]=ar[roota];
 }
}

bool setfind(int a[],int l,int m)
{
 return (root(a,l)==root(a,m));
}

int main()
{
int t;
cin>>t;
while(t--)
{
 int n;
 cin>>n;
 int a[n+1],siz[n+1];

 for(int i=0;i<=n;++i)
  {a[i]=i; siz[i]=1;}
  int x;
  cin>>x;
   int l,m;
  for(int i=0;i<x;++i)
   {
    cin>>l>>m;
    setunion(a,l,m,siz);
   }

   for(int i=0;i<=n;++i)
    cout<<a[i]<<"i"<<siz[i]<<" ";
    cout<<endl;
   /*

  int f;
  cin>>f;
  for(int i=0;i<f;++i)
   {cin>>l>>m;
    cout<<setfind(a,l,m)<<endl;
   }*/
 }
return 0;
}
