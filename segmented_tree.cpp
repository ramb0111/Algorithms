#include<bits/stdc++.h>
using namespace std;
int a[1000000];
 int segt[2000000];
void segTree(int pos,int left,int right,int segt[],int a[])
{
  if(left==right) {
      segt[pos]=a[left];return ;
  }
  else{
      int mid=(left+right)/2;
      segTree(2*pos+1,left,mid,segt,a);
      segTree(2*pos+2,mid+1,right,segt,a);
      segt[pos]=max(segt[2*pos+1],segt[2*pos+2]);
  }
}

int find(int l,int r,int findl,int findr,int pos,int segt[])
{
    if(findl<=l && r<=findr)
     return segt[pos];
    else if(r<findl || findr<l)
     return -1;
    else{ int mid=(l+r)/2;
        return max(find(l,mid,findl,findr,2*pos+1,segt),find(mid+1,r,findl,findr,2*pos+2,segt));
    }
}

int main()
 {  ios::sync_with_stdio(0);
    int n;
    cin>>n;
   for(int i=0;i<n;++i)
      cin>>a[i];
    int siz=1;
     while(siz<n){
     siz*=2;
     }
     segTree(0,0,n-1,segt,a);
     int k;
     cin>>k;
     for(int i=0;i+k-1<n;++i){
        printf("%d ",find(0,n-1,i,i+k-1,0,segt));
       }
     return 0;
 }
