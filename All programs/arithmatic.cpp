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
 *			Medium		: www.medium.com/@laxmena
 *
 *			Email		: lakshmanan.meiyappan@gmail.com
 *	
 */


#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <sstream>
#include <numeric>
#include <utility>
#include <string>
#include <vector>
#include <bitset>
#include <limits>
#include <time.h>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

#define SI(t) 	scanf("%d",&t)
#define SL(t) 	scanf("%ld",&t)
#define SLL(t) 	scanf("%lld",&t)
#define SC(t) 	scanf("%c",&t)
#define SS(t) 	scanf("%s",t)
#define SF(t) 	scanf("%f",&t)
#define SLF(t) 	scanf("%lf",&t)
#define all(cont) 	cont.begin(), cont.end()
#define rall(cont) 	cont.end(), cont.begin()
#define MP 		make_pair
#define PB 		push_back
#define MAX 	(int)1e9
#define EPS 	1e-9
#define PI 		3.1415926535897932384626433832795
#define MOD 	1000000007

const double pi=acos(-1.0);
typedef vector<int> VI;
typedef vector<string> VS;
typedef set<int> SETI;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;


void add(VI num1,VI num2){
	int size = max(num1.size(),num2.size());
	VI result[size+1];
	int sum,c;
	int i=num1.size() -1;
	int j=num2.size() -1;
	int carry = 0;
	while(i!=0 && j!=0){
		c = sum%10;
	}
}

int main(){
	int t;
	vector<int> num1;
	vector<int> num2;
	char op;
	bool flag;
	string s;
	SI(t);
	while(t-->0){
		cin>>s;
		flag = false;
		for(int i=0;i<s.size();i++){
			if(s[i] == '-' || s[i] == '+' || s[i] == '*')
				op = s[i++];
			if(!flag)
				num1.PB(int(s[i]));
			else
				num2.PB(int(s[i]));
		}
		cout<<endl<<num1[-1]<<endl<<num1[-2]<<endl<<num1[-3];
		// switch(op){
		// 	case '+': add(num1,num2);break;
		// 	case '-': sub(num1,num2);break;
		// 	case '*': mul(num1,num2);break;
		// }
	}
	return 0;
}