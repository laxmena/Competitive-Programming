#include <iostream>
#include <cstdio>
#include <vector>

#define ull unsigned long long

using namespace std;

vector<ull> fact;

ull findFact(int n){
	if(fact.size() >= n)
		return fact[n];
	for(int i=fact.size(); i<=n;i++){
		fact.push_back(fact[i-1]*i);
	}
	return fact[n];
}

int main(){
	int n;
	fact.push_back(1);
	scanf("%d",&n);
	cout<<findFact(n);
	return 0;
}