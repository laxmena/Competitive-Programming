#include <iostream>
#include <string>

using namespace std;

int main(){
	int max = 0,count=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='a' ||
		   s[i]=='e' ||
		   s[i]=='i' ||
		   s[i]=='u' ||
		   s[i]=='o'){
		   		count ++;
		   		if(count > max) max = count;
		   }
		else
			count = 0;
	}
	cout << max;
	return 0;
}
