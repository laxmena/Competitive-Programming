#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int checkSubStr(){
	string s1,s2;
	cin>>s1>>s2;
	int lastIndexS2 = s2.length()-1;
	int lastIndexS1 = s1.length()-1;
	
	int i=lastIndexS2, j=lastIndexS2;
	for(i;i<=lastIndexS1;i++){
		if(s1[i] == s2[lastIndexS2]){
			int f = 1;
			for(int x=0;x<=lastIndexS2;x++){
				if(s2[x] != s1[i-lastIndexS2+x])
					f = 0;
			}
			if(f==1)
				break;
		}
		i++;
	}
	return (i>lastIndexS1)?0:1;
}

int main(){
	int i = 24;
	while(i-->0)
		cout<<checkSubStr()<<endl;
	return 0;
}