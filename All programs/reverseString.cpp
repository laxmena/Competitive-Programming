#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

int main(){
	char input[100];
	scanf("%[^\n]s",input);
	assert(strlen(input)<100);
	for(int i=strlen(input)-1;i>-1;i--)
		printf("%c",input[i]);
	return 0;
}