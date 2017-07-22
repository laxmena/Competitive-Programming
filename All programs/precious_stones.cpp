#include <bits/stdc++.h>

using namespace std;

int findSecondMax(string s){
	int fmax = 0, smax = 0;
	int count = 0;
	int len = s.size();
	char temp;
	for(int i=0;i<len;i){
		count = 0;
		temp = s[i];
		while(i<len && s[i] == temp){
			count++;
			i++;
		}
		cout<<"Count "<<temp<<": "<<count<<endl;
		if(count >= fmax){
			smax = fmax;
			fmax = count;
		}
		else if(count > smax){
			smax = count;
		}
		cout<<"Fmax = "<<fmax<<", SMax = "<<smax<<endl;
	}
	return smax;
}

int main(){
	int t;
	string input;
	scanf("%d",&t);
	for(int iter=0; iter<t;iter++){
		cin>>input;
		cout<<"Case "<<iter<<": "<<findSecondMax(input)<<endl;
	}
	return 0;
}