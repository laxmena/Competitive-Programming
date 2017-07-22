#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

int calculateInt(string s){
	stack <int> exp;
	int count = 1;
	for(int i=0;i<s.size();i++){
		if(s[i] == '<'){
			if(exp.size() && exp.top() == '>')
				exp.pop();
			else{
				count++;
				exp.push(s[i]);
			}
		}
		else if(exp.size() && s[i] == '>'){
			if(exp.top() == '<')
				exp.pop();
			else{
				count++;
				exp.push(s[i]);
			}
		}
	}
	return count;
}

int main(){
	int ans, t;
	scanf("%d",&t);
	while(t-->0){
		string s;
		cin>>s;
		ans = calculateInt(s);
		cout<<ans<<endl;
	}
	return 0;
}

// 4
// <<<
// <><
// <=>
// <=<