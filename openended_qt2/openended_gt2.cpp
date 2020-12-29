#include<bits/stdc++.h>
using namespace std;

void print(int l,int u)
{
 for(int i=l;i<=u;i++)
 {
   int num;
   num=i;
   bool visited[10]={false};
   while(num)
   {
    if(visited[num%10])
    break;
    
    visited[num%10]=true;
    num=num/10;
    }
    if(num==0)
    cout<<i<<" ";
 }
}

int main()
{
 int lower,upper;
 cout<<"Enter lower and upper limit"<<endl;
 cin>>lower>>upper;
 cout<<"The unique numbers are"<<endl;
 print(lower,upper);
 cout<<endl;

 return 0;
}
