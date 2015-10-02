#include <iostream>
#include <vector>
#include<cstdio>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    /*
    Question - https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/deque-stl
    */
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
       int a[n];
       for(int i=0;i<n;++i)
           cin>>a[i];
       vector<int> v1(n),v2(n);
        int m=0;
       for(int i=0;i<n;++i){
           if(i%k==0)
              m=a[i];
           else m=max(m,a[i]);
           v1[i]=m;
       }
        m=0;
      for(int i=n-1;i>=0;--i){
           if(i%k==k-1)
              m=a[i];
           else m=max(m,a[i]);
           v2[i]=m;
       }
      for(int i=0;i<n-k+1;++i)
         printf("%d ",max(v1[i+k-1],v2[i]));
    printf("\n");
    }
    return 0;
}
