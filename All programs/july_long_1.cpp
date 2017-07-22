#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

char tolower(char target){
	if(target >= 'a' && target <= 'z')
		return target;
	return target+32;
}

char toUpper(char target){
	if(target >= 'A' && target <= 'Z')
		return target;
	return target-32;
}

int main(){
	int t, blocks, i, n;
	char input[10001];
	scanf("%d",&t);
	while(t-->0){
		blocks = 0;
		scanf("%[^\n]s",input);
		n = strlen(input);
		for(i=0;i<n;i++)
			if(input[i] == ' ')
				blocks ++;
		for(i=0;i<n;){
			if(input[i] == ' ' && i<n)
				blocks--;
			if(blocks > 0){
				cout<<toUpper(input[i])<<". ";
				i += 1;
				while(input[i] != ' ')
					i++;
			}
			else{
				cout<<toUpper(input[i++]);
				while(i<n)
					cout<<input[i++];
			}
		}
	}
	return 0;
}