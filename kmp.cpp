#include<iostream>
using namespace std;

void longestPrefixsuffix(int arr[],string pattern){
 int i=0,j=1;    // j is the index for pattern and i is for lps
 arr[0]=0;
 while(j<pattern.size()){
  if(pattern[i]==pattern[j]){
    arr[j]=i+1;
    ++i;++j;
  }
  else{
     if(i==0){
      arr[j]=0;
      ++j;
     }
     else i=arr[i-1];   // to check every previous half array for longest prefix which i also suffix
  }

 }
}

void kMPMatcher(string text,string pattern,int arr[]){
  int i=0,j=0;
  while(j<text.size()){
     if(pattern[i]==text[j]){
        ++i;++j;

       if(i==pattern.size()){
        cout<<"Matching at index"<<j-i<<endl;
        i=arr[i-1];
       }
     }
     else{
       if(i==0)
        ++j;
       else
       i=arr[i-1];
     }
  }
}

int main(){
string text,pattern;
cin>>text>>pattern;
int preprocessarray[pattern.size()];
longestPrefixsuffix(preprocessarray,pattern);
kMPMatcher(text,pattern,preprocessarray);
return 0;
}
