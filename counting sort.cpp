#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int input[n],maximum=-1,output[n];
for(int i=0;i<n;++i)
  {cin>>input[i];
   maximum=max(maximum,input[i]);
  }

int frequency[maximum+1];

for(int i=0;i<=maximum;++i)
    frequency[i]=0;

for(int i=0;i<n;++i)
  ++frequency[input[i]];

for(int i=1;i<=maximum;++i)
   frequency[i]+=frequency[i-1];

for(int i=0;i<n;++i){
  output[frequency[input[i]]-1]=input[i];
  --frequency[input[i]];
}

for(int i=0;i<n;++i)
 cout<<output[i]<<" ";

return 0;
}
