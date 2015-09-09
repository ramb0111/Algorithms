#include<bits/stdc++.h>
using namespace std;

int visited[11]={0};   // u can enter 1 to 10
 vector<int> vertex[11];

void dfs(int node)
 {
   visited[node]=1;
   for(int i=0;i<vertex[node].size();++i)   // mark all immediate node one by one and calling dfs on each node
        if(!visited[vertex[node][i]])
          dfs(vertex[node][i]);         // calling dfs
 }


 int main()
 {
 int n,e;
 cin>>n>>e;
 int x,y;
 for(int i=0;i<e;++i){
  cin>>x>>y;
  vertex[x].push_back(y);
  vertex[y].push_back(x);
 }

 int components=0;
 for(int i=1;i<=n;++i)
   {
   if(!visited[i])
     {dfs(i);
      ++components;
     }
   }
 cout<<"There are "<<components<<" components\n";
 return 0;
 }
