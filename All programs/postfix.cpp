#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;


int precedence(char exp){
	switch(exp){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
}
int main(){
	int t=1;
	while(t-->0){
		string exp;
		stack<char> s;
		cin>>exp;
		int p;
		for(int i=0;i<exp.length();i++){
			if(exp[i]>47 && exp[i]<58)
				cout<<exp[i];
			else if(exp[i]!='(' && exp[i]!=')'){
				if(s.size() == 0)
					s.push(exp[i]);
				else if(precedence(s.top()) < precedence(exp[i])){
					cout<<exp[i];
					cout<<s.top();
					s.pop();
				}
				else
					s.push(exp[i]);
			}
		}
		while(s.size()){
			cout<<s.top();
			s.pop();
		}
	}	
}