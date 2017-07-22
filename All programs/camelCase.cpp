#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	char s[200];
	bool newWord = true;
	scanf("%[^\n]s",s);
	for(int i=0;i<strlen(s);i++){
		if(newWord){
			cout<<char(s[i]-32);
			newWord = false;
		}			
		else if(s[i] == ' ')
			newWord = true;
		else
			cout<<s[i];
	}
	return 0;
}
