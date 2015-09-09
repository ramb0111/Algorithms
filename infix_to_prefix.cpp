#include<bits/stdc++.h>
using namespace std;
int main()
 {  ios::sync_with_stdio(0);
   int t;
   cin>>t;
   while(t--){
       string s;
        cout<<"See the question link for prescribed input\n";
       /*
        http://www.spoj.com/problems/ONP/
        but the program calculates the prefix not postfix
       */
       cin>>s;
       stack<int> st;
       for(int i=0;i<s.size();++i){
          if(s[i]=='(')
           st.push(i);
          else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
           s[st.top()]=s[i];
           st.pop();
           s.erase(s.begin()+i);
           --i;
           }
          else if(s[i]==')'){s.erase(s.begin()+i); --i;}
       }
      printf("%s\n",s.c_str());
   }
 }
