%{
	#include<stdio.h>
	int sum=0,temp;	
%}
letter [a-zA-Z]
digit [0-9]

%%
{letter}+ {printf("found a letter %s\n",yytext);}
{digit}+ {sscanf(yytext,"%d",&temp);
sum += temp;
printf("Found a number: %d",temp);
printf("Total Value: %d",sum);}
%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 0;
}