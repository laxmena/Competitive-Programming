#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void printer(std::vector<int> a){
// void printer(vector<int> &a, int l,int r){
  for(int i=0;i<a.size();i++){
  // for(int i=l;i<=r;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

void merge(vector<int> &a,int l,int m,int r){
  // int n1=m-l;
  // int n2=r-m;
  // cout<<"n1: "<<n1<<" n2: "<<n2<<" l: "<<l<<" r: "<<r<<" Merge: "<<endl;
  // printer(a,l,m);
  // cout<<endl<<"m->r";
  // printer(a,m+1,r);
  int i,j,k;
  vector<int> lv,rv;
  for(i=l;i<=m-l;i++)
    lv.push_back(a[i]);
  for(i=m;i<=r;i++)
    rv.push_back(a[i]);
  cout<<"lv: ";
  printer(lv);
  cout<<"rv: ";
  printer(rv);
  i = 0;
  j = 0;
  k = l;

  while(i<lv.size() && j<rv.size()){
    cout<<"Before = i: "<<i<<" j: "<<j<<endl;
    if(lv[i]<=rv[j]){
      cout<<"lv[i]("<<lv[i]<<") is lesser than rv[j]("<<rv[j]<<")"<<endl;
      a[k]=lv[i];
      k++;
      i++;
    }
    else{
      cout<<"rv[j]("<<rv[j]<<") is lesser than lv[i]("<<lv[i]<<")"<<endl;
      a[k]=rv[j];
      k++;
      j++;
    }
    cout<<"After = i: "<<i<<" j: "<<j<<endl;
    printer(a);
  }
  while(i<lv.size()){
    a[k]=lv[i];
    k++;
    i++;
  }
  while(j<rv.size()){
    a[k]=rv[j];
    k++;
    j++;
  }
}

void mergesort(vector<int> &a,int l,int r){
    if(r>l){
      int m=(l+r)/2;
      mergesort(a,l,m);
      // printer(a,l,m);
      mergesort(a,m+1,r);
      // printer(a,m+1,r);
      merge(a,l,m,r);
    }
    return;
}

int main(){
  vector<int> a;
  int arr[] = {21,32,12,13,41,234,21};
  for(int i=0;i<7;i++){
    a.push_back(arr[i]);
  }
  mergesort(a,0,a.size()-1);
  printer(a);
  return 0;
}
