#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

//http://www.geeksforgeeks.org/the-stock-span-problem/
//the_stock_span_problem.cpp

void claculateSpan(vector<int> v, int n, int s[]){
	stack<int> stk;
	stk.push(0);
	s[0] = 1;
	int i;
	for(i=1;i<n;i++){
		while(!stk.empty() && v[stk.top()] <= v[i])
			stk.pop();
		s[i] = (stk.empty())? (i+1) : (i-stk.top());
		stk.push(i);
	}
}

int main(){
	int n,i,t;
	vector<int> v;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		v.push_back(t);
	}
	int s[n];
	claculateSpan(v,n,s);
	for(i=0;i<n;i++)
		cout<<s[i]<<" ";
	return 0;
}