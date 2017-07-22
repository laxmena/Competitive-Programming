#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	long long int t,n,r,i,temp;
	scanf("%lld",&t);
	while(t-->0){
		scanf("%lld %lld",&n,&r);
		r = r%n;
		vector<long long int> arr;
		for(i=0;i<n-r;i++){
			scanf("%lld",&temp);
			arr.push_back(temp);
		}
		for(i=0;i<r;i++){
			scanf("%lld",&temp);
			printf("%lld ",temp);
		}
		for(i=0;i<arr.size();i++)
			printf("%lld ",arr[i]);
		printf("\n");
	}
	return 0;	
}