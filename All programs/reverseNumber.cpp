#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int input, result;
	cin>>input;

	result = 0;

	while(input){
		result = result*10 + input%10;
		input /=  10;
	}

	printf("%d",result);
	return 0;
}