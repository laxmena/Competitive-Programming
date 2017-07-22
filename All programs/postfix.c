#include<stdio.h>
#include<string.h>

int main(){
	char exp[100];
	int i,n,l;
	printf("Enter PostFix Expression: ");
	scanf("%s",exp);
	n = strlen(exp);
	for(i=0;i<n;i++){
		printf("%c",exp[i]);
		if(n-1>i)
			printf("%c",exp[n-1]);
		n-=1;
	}
	printf("\n");
	return 0;
}

