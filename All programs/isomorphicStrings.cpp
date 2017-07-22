#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
	string s1, s2;
	cin>>s1>>s2;
	int l1,l2,i;
	l1 = s1.size();
	l2 = s2.size();
	map<char, char> subs;

	if(l1 != l2){
		cout<<"false";
		return -1;
	}
	while(i < l1){
		if(subs.find(s1[i]) == subs.end()){
			subs[s1[i]] = s2[i];
		}
		else if(subs[s1[i]] != s2[i]){
				cout<<"false";
				return -1;
		}
		i++;
	}
	cout<<"true";
	return 0;	
}