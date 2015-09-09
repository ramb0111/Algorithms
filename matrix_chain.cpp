/*
  Program to findout the best parentesization order such that the cost of multiplying
   n matrices is minimum
*/

#include<iostream>
#include<vector>
using namespace std;
#define high 10e9


/* function to calculate 2 matrices , 1 to find out the cost of possible parenthesizations(mat) and
   other(orderMat) to store the breaking points
*/
void optimumcost(int n,int p[],vector<vector<int> > &orderMat,vector<vector<int> > &mat){
  for(int i=1;i<=n;++i)
    mat[i][i]=0;

  for(int l=2;l<=n;++l){
    for(int i=1;i<=n-l+1;++i){
        int j=i+l-1;
        mat[i][j]=high;
        for(int k=i;k<j;++k){
           int temp=mat[i][k]+ mat[k+1][j]+p[i-1]*p[k]*p[j];
           if(mat[i][j]>temp){
             mat[i][j]=temp;
             orderMat[i][j]=k;
           }
        }
    }
  }
}

// Breakage points are used to findout to place the parenthesis
void order(vector<vector<int> >ar,int i,int j){
 if(i==j)
  cout<<i;
  else{
    cout<<"(";
    order(ar,i,ar[i][j]);
    order(ar,ar[i][j]+1,j);
    cout<<")";
  }
}

int main(){
int n;
cout<<"Enter the number of matrices\n";
cin>>n;
int p[n+1];
cout<<"Enter the matrices in order p0, p1, .... pn\n";
for(int i=0;i<=n;++i)
  cin>>p[i];
vector<vector<int> >mat(n+1,vector<int>(n+1)),parenthesis(n+1,vector<int>(n+1));

optimumcost(n,p,parenthesis,mat);
cout<<"\nOrder of parenthesization is : ";
order(parenthesis,1,n);
cout<<"\n";
return 0;
}
