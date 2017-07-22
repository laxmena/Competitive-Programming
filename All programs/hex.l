%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	void dectoheex(int);
%}
%%
%%
void dectohex(int dec){
	int a[10],t,n=dec,n1=dec,i=0,j;
	while(n>0){
		t = n%16;
		a[i++] = t;
		n/=16;
	}
	j = i;
	for(i=0;i<j;i++){
		switch(a[i]){
			case 10: printf("A");break;
			case 11: printf("B");break;
			case 12: printf("C");break;
			case 13: printf("D");break;
			case 14: printf("E");break;
			case 15: printf("F");break;
			default: printf("%d",a[i]);
		}
	}
}

main(){
	int dec;
	printf("Enter a decimal: ");
	scanf("%d",&dec);
	dectohex(dec);
	return 0;
}

int yywrap(){
	return 0;
}