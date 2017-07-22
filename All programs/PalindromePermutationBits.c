//Palindrome Permutation using Bit Vector

#include<stdio.h>
#include<string.h>

int checkPairity(int check){
	if(check == 0)
		return 1;
	if(((check -1)&check) == 0)
		return 1;
	return 0;
}

int convertCharacter(int c){
	if(c >= 'A' || c <= 'Z')
		return c-'A'+'a';
	if(c >= 'a' || c <= 'z')
		return c - 'a';
	return -1;
}

int palidromePermutationChecker(char phrase[]){
	int check = 0;
	int i = 0;
	int temp;
	int n = strlen(phrase);

	for(i=0;i<n;i++){
		temp = convertCharacter(phrase[i]);
		if(temp){
			check = check | (1<<temp);
			printf("After %c\t Check = %d\n",phrase[i],check);
		}
	}
	return check;
}

int main(){
	int check;
	char phrase[100];
	scanf("%[^\n]s",phrase);
	check = palidromePermutationChecker(phrase);
	if(checkPairity(check))
		printf("True\n");
	else
		printf("Fasle\n");
	return 0;
}