#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<long long int,long int> dict;
map<long long int,long int> :: iterator it;

long int find5s(int inp){
	
}

int main(){
	long long int zeros,temp,i=0,n;
	long int t;
	cin>>t;
	while(t-->0){
		zeros=0;
		cin>>n;
		for(i=5;i<=n;i+=5){
			zeros += find5s(i);
		}
		printf("%lld\n",zeros);
	}
	return 0;
}