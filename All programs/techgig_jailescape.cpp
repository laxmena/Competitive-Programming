#include<iostream>

using namespace std;

int main(){
  long long int temp,c,x,y,n,t,s;
  cin>>x>>y>>n;
  s = x-y;
  c = 0;
  while(n-->0){
    cin>>t;
    temp = 0;
    while(1){
      if(temp<t){
        if(temp+s+1 != t)
          temp+=s;
        else
          temp+=s+1;
        c++;
      }
      else
        break;
    }
  }
  cout<<c<<endl;
  return 0;
}
