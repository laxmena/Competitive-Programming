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
 *			Attribution : https://github.com/laxmena/Competitive-Programming/blob/master/Template/template.cpp
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
#define SS(t) 	cin>>t
#define SF(t) 	scanf("%f",&t)
#define SLF(t) 	scanf("%lf",&t)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(container) container.begin(), container.end()
#define rall(container)	container.end(), container.begin()
#define RFOR(i, from, till, dec) for(i=from; i>=till; i-=dec)
#define FOR(i, from, till, inc) for(i=(from); i<(till); i+=(inc))
#define FOREACH(it, container) for (it = container.begin(); it != container.end(); it++)
 
#define MP 		make_pair
#define PB 		push_back
#define MAX 	(int)1e9
#define EPS 	1e-9
#define PI 		3.1415926535897932384626433832795
#define MOD 	1000000007
 
const double pi=acos(-1.0);
typedef vector<int> VI;
typedef vector<float> VF;
typedef vector<string> VS;
typedef list<int> LI;
typedef list<string> LS;
typedef set<int> SETI;
typedef set<char> SETC;
typedef set<float> SETF;
typedef stack<int> STACKI;
typedef stack<char> STACKC;
typedef stack<float> STACKF;
typedef queue<int> QI;
typedef queue<char> QC;
typedef queue<float> QF;
typedef map<int,int> MAPII;
typedef map<int,char> MAPIC;
typedef map<char,int> MAPCI;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;
 
//https://www.codechef.com/problems/CLEANUP
int main(){
	int i,temp,t,m,n;
	SI(t);
	while(t-->0){
		//Total number of Jobs
		SI(n);
		//Total jobs completed
		SI(m);
		//Create an list to keep track of Jobs
		LI jobs;
		LI :: iterator it;
		FOR(i,1,n+1,1) jobs.PB(i);
		REP(i,m){
			SI(temp);
			jobs.remove(temp);
		}
		i = 0;
		FOREACH(it,jobs) {
			if(i%2 == 0) printf("%d ",*it);
			i++;
		}
		printf("\n");
		i = 0;
		FOREACH(it,jobs){ 
			if(i%2 == 1) printf("%d ",*it);
			i++;
		}
		printf("\n");
	}
	return 0;
} 