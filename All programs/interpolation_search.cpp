#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int interpolation_search(vector<int> a,int n, int x){
  int l=0,h=(n-1);
  while(l<=h && a[l]<=x && x<=a[h]){
    int pos = l + (x-a[l])*(h-l)/(a[h]-a[l]);
    if(a[pos]==x)
      return pos;
    if(a[pos]<x)
      l = pos+1;
    else
      h = pos-1;
    cout<<"Count!"<<endl;
  }
  return -1;
}

int main(){
  int i=1;
  vector <int> a;
  while(i<=15){
    a.push_back(i*i++);
  }
  for(i=0;i<a.size();i++)
    cout<<"a["<<i<<"] = "<<a[i]<<endl;
  int n;
  cin>>n;
  cout<<interpolation_search(a,a.size(),n)<<endl;
  return 0;
}
