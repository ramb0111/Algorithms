#include<bits/stdc++.h>
using namespace std;

int level[11],visited[11]={0};
vector<int> vertex[11];

void bfs(int source)
 {
    queue<int> q;
    q.push(source);
    level[source]=0;
    visited[source]=1;
    while(q.size())
    {
     int node=q.front(); q.pop();

    for(int i=0;i<vertex[node].size();++i)        // push all immediate nodes in queue and mark them visited along with level
       if(!visited[vertex[node][i]])
        {
          level[vertex[node][i]]=level[node]+1;
          visited[vertex[node][i]]=1;
          q.push(vertex[node][i]);
        }
    }
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

 int source;
 cin>>source;
  bfs(source);

 for(int i=1;i<=n;++i)
   cout<<level[i]<<" ";
return 0;
}
