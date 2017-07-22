#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int binary(vector <int> v,int l,int r,int x){
  int mid;
  if(r>=l){
    mid = (l+r)/2;
    if(v[mid]==x)
      return mid;
    if(v[mid]<x)
      return binary(v,mid+1,r,x);
    else if(v[mid]>x)
      return binary(v,l,mid-1,x);
  }
  if(r==l && v[mid]==x)
    return mid;
  return -1;
}

int exp(vector <int> v,int x){
  int i=1,n=v.size();
  if(v[i] == x)
    return i;
  while(i<n && v[i]<x){
    i*=2;
  }
  return binary(v,i/2,min(i,n-1),x);
}

int main(){
  int n,i=0;
  vector<int> v;
  while(i++<15)
    v.push_back(i);
  cin>>n;
  int result = exp(v,n);
  if(result==-1)
    cout<<"Not Found!"<<endl;
  else
    cout<<n<<" is found in location "<<result;
  return 0;
}
