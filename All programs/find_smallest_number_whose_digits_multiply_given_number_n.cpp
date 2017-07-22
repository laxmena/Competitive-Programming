#include <iostream>
#include <cstdio>

#define MAX 50

using namespace std;

//http://www.geeksforgeeks.org/find-smallest-number-whose-digits-multiply-given-number-n/
//find-smallest-number-whose-digits-multiply-given-number-n

void findSmallestNum(int n){
	int result[MAX];
	int i,j=0;
	if(n<10){
		printf("%d",n+10);
		return;
	}
	for(i=9;i>1;i--){
		while(n%i == 0){
			result[j++] = i;
			n /= i;
		}
	}
	if(n>10){
		printf("Not Possible\n");
		return;
	}
	for(i=j-1;i>=0;i--){
		printf("%d",result[i]);
	}
}

int main(){
	int n;
	printf("Enter the number n: ");
	scanf("%d",&n);
	findSmallestNum(n);
	return 0;
}