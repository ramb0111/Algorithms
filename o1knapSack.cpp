#include<iostream>
using namespace std;

int main(){
 int n;
 cout<<"Enter the number of elements\n";
 cin>>n;
 cout<<"Enter their weights and values repsectively line by line each of them\n";
 pair<int,int> a[n];
 for(int i=1;i<=n;++i)
  {cout<<"W["<<i<<"]= ";cin>>a[i].first;
   cout<<"V["<<i<<"]=";cin>>a[i].second;
  }
int W;
cout<<"Enter the capacity of the sack\n";
cin>>W;

  int mat[n+1][W+1];

  for(int i=0;i<=n;++i){
  for(int j=0;j<=W;++j){
      if(i==0 || j==0)
        mat[i][j]=0;
      else if(j<a[i].first)
          mat[i][j]=mat[i-1][j];
        else mat[i][j]=max(a[i].second+mat[i-1][j-a[i].first],mat[i-1][j]);
    }
  }

 cout<<"Maximized value is "<<mat[n][W]<<endl;
  return 0;
}
