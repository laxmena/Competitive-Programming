#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int jump(vector<int> arr, int x){
  int i=0;
  int step = sqrt(arr.size());
  while(i<arr.size() && arr[i] <=x){
    i+=step;
    i = min(i,(int)arr.size());
    printf("\nArray Size: %d\nLocation of i: %d\nStep: %d\n",(int)arr.size(),i,step);
  }
  if(i==arr.size())
    i--;

  while(arr[i]>=x){
    if(arr[i]==x)
      return i;
    i--;
  }
  return -1;
}

int main(){
  int x,n,i,t;
  scanf("%d",&n);
  vector <int> arr;
  for(i=0;i<n;i++){
      scanf("%d",&t);
      arr.push_back(t);
    }
  printf("Enter Search Element: ");
  scanf("%d",&x);
  t = jump(arr,x);
  if(t!=-1)
    printf("\n%d is present at location: %d",x,t);
  else
    printf("\nElement is not present");
  return 0;
}
