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
 *			Attribution : https://github.com/laxmena/Competitive-Programming/blob/master/Template/Template2.cpp
 *	
 */


#include <bits/stdc++.h>

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
#define FOREACH(it, container) for(it=container.begin(); it != container.end(); it++)

#define MP 		make_pair
#define PB 		push_back
#define MAX 	(int)1e9
#define EPS 	1e-9
#define PI 		3.1415926535897932384626433832795
#define MOD 	1000000007

const double pi=acos(-1.0);
typedef vector<int> VI;
typedef vector<float> VF;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<long> VL;
typedef list<int> LI;
typedef list<string> LS;
typedef set<int> SETI;
typedef set<char> SETC;
typedef set<float> SETF;
typedef set<long> SETL;
typedef set<long long> SETLL;
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

int matrix[100][100] = {0};
SETI primes;

void generatePrimes(int upperBound){
	int i,j;
	VB sieve(upperBound+1,true);
	FOR(i,2,upperBound+1,1)
		if(sieve[i] == true){
			primes.insert(i);
			FOR(j,i*i,upperBound+1,i) sieve[j]=false;
		}
}

int main(){
	int n,i,j,sum,count;
	SI(n);
	REP(i,n)
		REP(j,n)
			SI(matrix[i][j]);
	count = 0;
	generatePrimes(400);

	REP(i,n){
		REP(j,n){
			sum = 0;
			if((i-1) > -1) sum += matrix[i-1][j];
			if((i+1) < n)  sum += matrix[i+1][j];
			if((j-1) > -1) sum += matrix[i][j-1];
			if((j+1) < n)  sum += matrix[i][j+1]; 
			if(primes.find(sum) != primes.end()) count++;
		}
	}
	cout<<count;
	return 0;
}