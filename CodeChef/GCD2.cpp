/*
 *  Author: Lakshmanan Meiyappan
 *  Handle: Codechef	: lax2804
 *			HackerRank	: lax2804
 *			HackerEarth	: @lakshmanan.meiyappan
 *			SPOJ		: laxmena
 *
 *			GitHub		: https://github.com/laxmena			
 *	
 *			Website		: https://laxmena.github.io/website/
 *
 *			Email		: lakshmanan.meiyappan@gmail.com
 *			Attribution : https://github.com/laxmena/Competitive-Programming/blob/master/Template/template2.cpp
 *	
 */


#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int calcMod(int a,string b){
	int result = 0;
	for(int i=0;i<b.size();i++){
		result = result*10 + (b[i]-'0');
		result %= a;
	}
	return result;
}

int main(){
	int a,t,bVal;
	string b;
	scanf("%d",&t);
	while(t-->0){
		scanf("%d",&a);
		cin>>b;
		if(a==0) cout<<b<<"\n";
		else {
			bVal = calcMod(a,b);
			cout<<gcd(a,bVal)<<"\n";
		}
	}
	return 0;
}