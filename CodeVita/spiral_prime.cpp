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

struct pos{
	int x,y;
}result;

void getTileCoordinates(l tileNum){
    int intRoot=floor(sqrt(tileNum));

    int x=(round(intRoot/2)*pow(-1,intRoot+1))+(pow(-1,intRoot+1)*(((intRoot*(intRoot+1))-tileNum)-abs((intRoot*(intRoot+1))-tileNum))/2);

    int y=(round(intRoot/2)*pow(-1,intRoot))+(pow(-1,intRoot+1)*(((intRoot*(intRoot+1))-tileNum)+abs((intRoot*(intRoot+1))-tileNum))/2);
    
    result.x = x;
    result.y = y;
    return;
}

//Sieve of Sundaram
int main(){
	l i,n,j,tileNum,intRoot,t,searchPrime;
	SL(t);
	while(t-->0){
	n = 1000000;
	VI prime;
	int nNew = (n-2)/2;
	vector<bool> marked(n+1,true);
	for(i=1;i<nNew+1;i++){
		j = i;
		while((i + j + 2*i*j) <= nNew){
			marked[i + j + 2*i*j] = false;
			j++;
		}
	}
	for(i=1;i<nNew+1;i++)
		if(marked[i]) prime.PB(2*i+1);
	SL(searchPrime);
	REP(i,prime.size()){
		if(prime[i] == searchPrime){
			getTileCoordinates(i);
		}
	}

	cout<<result.x<<" "<<result.y<<endl;
	}
	return 0;	
}