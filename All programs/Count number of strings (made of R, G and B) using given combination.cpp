#include <iostream>
#include <cstdio>

using namespace std;

//Count number of strings made of r-g-b using given combinations
//http://www.geeksforgeeks.org/count-number-of-strings-made-of-r-g-and-b-using-given-combination/

int main(){
	int n,r,g,b,i,j,k,left,sum;
	scanf("%d%d%d%d",&n,&r,&g,&b);
	int fact[n+1];
	fact[0] = 1;
	for(i=1;i<=n;i++)
		fact[i] = i*fact[i-1];
	left = n - (r+g+b);
	sum = 0;

	for(i=0;i<=left;i++){
		for(j=0;j<=left-i;j++){
			k = left - (i+j);
			sum = sum + (fact[n]/(fact[i+r]*fact[j+g]*fact[k+b]));
		}
	}

	cout<<sum;

	return 0;
}