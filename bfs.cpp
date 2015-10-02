#include <bits/stdc++.h>
using namespace std;

void bfs(int s,vector<int> a[],int mark[]){
  queue<int> q;
   q.push(s);
   mark[s]=0;
  while(q.size()){
   for(int i=0;i<a[q.front()].size();++i){
       if(mark[a[q.front()][i]]==-1)
       {mark[a[q.front()][i]]=1+mark[q.front()];
        q.push(a[q.front()][i]);
       }
    }
   q.pop();
  }
}

int main() {
    int t;
    cin>>t;  // Number of test cases
    while(t--){
        int n,m;
        cin>>n>>m;  // Number of nodes and edges
        vector<int> a[n+1];
        int mark[n+1];
        for(int i=1;i<=n;++i)
           mark[i]=-1;
        int x,y;
        for(int i=0;i<m;++i){
            cin>>x>>y;  // Edges
            a[x].push_back(y);
            a[y].push_back(x);
        }
       int s;
       cin>>s;   // Source node
       bfs(s,a,mark);
       for(int i=1;i<=n;++i){
            printf("%d ",mark[i]);   // Level of each node from the source node
       }
       printf("\n");
    }
    return 0;
}
