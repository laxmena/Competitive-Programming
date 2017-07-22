//Palindrome Permutation

#include<stdio.h>
#include<string.h>

int checkPlaindromePermutation(char input[]){
	int pairity = 0;
	int temp,i,len;
	int count['z'-'a'+1];

	len = strlen(input);
	for(i=0;i<len;i++){
		temp = input[i];
		if(temp >= 'A' && temp <= 'Z')
			temp = temp - 'A' + 'a';
		if(temp >= 'a' && temp <= 'z'){
			count[temp - 'a'] += 1;
			if(count[temp - 'a']%2 == 0)
				pairity--;
			else
				pairity++;
		}
	}
	if(pairity<2)
		return 1;
	return 0;
}

int main(){
	char palindrome[100];
	scanf("%[^\n]s",palindrome);
	if(checkPlaindromePermutation(palindrome)){
		printf("\nIs a palindrome Permutation");
	}
	else{
		printf("\nIs not a palindrome permutation");
	}
	return 0;
}