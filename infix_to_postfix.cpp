#include<bits/stdc++.h>
using namespace std;

int main()
 {  ios::sync_with_stdio(0);
   int t;
   cin>>t;
   while(t--){
       string s,s1;
       cin>>s;
       stack<int> st;
       for(int i=0;i<s.size();++i){
           if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
           st.push(s[i]);
           else if(s[i]==')'){
            s1+=st.top();
            st.pop();
           }
           else if(s[i]!='(')
           s1+=s[i];
       }
      printf("%s\n",s1.c_str());
   }
 }
