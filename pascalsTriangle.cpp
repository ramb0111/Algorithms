/*
  Program to print the sequence of Pascal's Triangle
*/

#include<bits/stdc++.h>
using namespace std;

int main()
 {
 cout<<"Enter the size of the Pascal's Triangle (between 1 &50)\n";
 int n;
 cin>>n;
 long long a[n][n];
 for(int i=0;i<n;++i)
     for(int j=0;j<=i;++j)
        if(j==0||j==i)
           a[i][j]=1;
       else a[i][j]=a[i-1][j]+a[i-1][j-1];
cout<<"\nPascal's Triangle:\n\n";
 for(int i=0;i<n;++i)
     {for(int j=0;j<=i;++j)
         printf("%lld ",a[i][j]);
      printf("\n");
     }
 return 0;
 }
