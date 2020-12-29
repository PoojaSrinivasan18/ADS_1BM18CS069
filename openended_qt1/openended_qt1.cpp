#include <bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 cout<<"Enter no of test cases"<<endl;
 cin>>t;
 while(t--)
 {
   int n;
  int arr[n];
 
  cout<<"Enter no of elements in the array"<<endl;
  cin>>n;
  cout<<"Enter elements of the array"<<endl;

  for(int i=0;i<n;i++)
  cin>>arr[i];
  
  cout<<endl;
  sort(arr,arr+n);
  
  for(int i=0;i<n-2;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
  }
  return 0;
 }
