#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

//Sieve of Sundaram
int main(){
	int n,j;
	scanf("%d",&n);
	int nNew = (n-2)/2;
	vector<bool> marked(n+1,true);
	for(int i=1;i<nNew+1;i++){
		j = i;
		while((i + j + 2*i*j) <= nNew){
			marked[i + j + 2*i*j] = false;
			j++;
		}
	}
	if(n>2) cout<<2<<" ";
	for(int i=1;i<nNew+1;i++)
		if(marked[i]) cout<<2*i+1<<" ";
	return 0;	
}