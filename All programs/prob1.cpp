#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n;
	int s = 6,diff = 22;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			printf("%05d",s);
			s = s+diff;
			diff += 16;
		}
		cout<<"\n";
	}
	return 0;	
}