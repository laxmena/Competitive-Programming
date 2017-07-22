#include<vector>
#include<iostream>

using namespace std;

void swap(int *a,int *b){
  int t = *a;
  *a = *b;
  *b = t;
}

void ssort(vector<int> &a,int size){
  int i,j,min;
  for(i=0;i<size-1;i++){
    min = i;
    for(j=i+1;j<size;j++){
      if(a[j]<a[i])
        min = j;
    }
    swap(&a[i],&a[min]);
  }
}

void printer(vector<int> a,int size){
  for(int i=0;i<size;i++){
    cout<<a[i]<<" ";
  }
}

int main(){
  int t,n;
  vector<int> a;
  cout<<"Enter number of Elements: ";
  cin>>n;
  std::cout << "Enter Elements: " << '\n';
  while(n-->0){
    cin>>t;
    a.push_back(t);
  }
  ssort(a,a.size());
  printer(a,a.size());
  return 0;
}
