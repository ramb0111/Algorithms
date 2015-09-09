#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > a,b;

int main()
 {  ios::sync_with_stdio(0);
   int t;
   cin>>t;
   while(t--){
       string s;
       cin>>s;
       stack<int> q;
       for(int i=0;i<s.size();++i){
          if(s[i]=='(')
           q.push(i);
          else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
           s[q.top()]=s[i];
           q.pop();
           s.erase(s.begin()+i);
           }
          else if(s[i]==')'){s.erase(s.begin()+i); --i;}
       }
      printf("%s\n",s.c_str());
   }
 }
