#include<bits/stdc++.h>
using namespace std;
int a[1001],siz[1001];
pair<long long,pair<int,int> > pr[10];

int root(int x){
 int parent=x;
 while(parent!=a[parent]){
    parent=a[parent];
 }
 int temp;
 while(parent!=x){
    temp=a[x];
    a[x]=parent;
    x=temp;
 }
}

void disjoint_set_union(int x,int y){
int xroot=root(x),yroot=root(y);
  if(siz[xroot]>siz[yroot]){
  siz[xroot]+=siz[yroot];
  a[yroot]=a[xroot];
  }
  else {
  siz[yroot]+=siz[xroot];
  a[xroot]=a[yroot];
  }
}

int kruskal(int n){
 int x,y,mincost=0,county=0;
 long long wt;
 for(int i=0;county<n-1;++i){
  x=pr[i].second.first;
  y=pr[i].second.second;
  wt=pr[i].first;
  if(root(x)!=root(y)){
   ++county;
   mincost+=wt;
   disjoint_set_union(x,y);
  }
 }
 return mincost;
}

int main(){
int n,e;
cin>>n>>e;

for(int i=1;i<=n;++i){
siz[i]=1;a[i]=i;
}

int x,y;long long wt;
for(int i=0;i<e;++i){
 cin>>x>>y>>wt;
  pr[i]=make_pair(wt,make_pair(x,y));
 }
 sort(pr,pr+e);
 int min_cost=kruskal(n);
 cout<<min_cost<<"\n";
return 0;
}
