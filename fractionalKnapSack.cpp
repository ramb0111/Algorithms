#include<bits/stdc++.h>
using namespace std;

int main()
 {
   /* Program of fractional KnapSack implementation
    i/p: size and value of each product along with the capacity of the Sack
    o/p: maximize the value corresponding to capacity
    */

    int num,capacity,ans=0;
    cout<<"Enter the number of items:\n";
    cin>>num;
    multimap <float,float,greater<int> > m;
    cout<<"\nEnter the size along with the values:\n";
    float siz,value;
    for(int i=0;i<num;++i)
         {cin>>siz>>value;
          m.insert(pair<int,int>(value/siz,siz));
         }
    cout<<"\nEnter the capacity of the Sack:\n";
    cin>>capacity;
    multimap<float, float> :: iterator itr;
    for(itr=m.begin();itr!=m.end();++itr)
    {   int temp=itr->second;
        if(temp<capacity)
            {ans+= temp*(itr->first);
             capacity -=temp;
            }
       else {ans+=capacity*(itr->first);
             capacity=0;
             break;
             }
    }
   cout<<"\n\nThe maximum possible value is: "<<ans<<"\n";
 return 0;
 }
