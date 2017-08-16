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
#define PIN(i) printf("%d\n",i);
#define PL(l) printf("%ld ",l);
#define PLN(l) printf("%lld",l);

#define MP 		make_pair
#define PB 		push_back
#define MAX 	(int)(1e9+7)
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

ll gcd(ll a,ll b){return (b==0)?a: gcd(b,a%b);}
ll lcm(ll a, ll b){return (a*b)/gcd(a,b);}
ll modpow(ll a,ll n,ll temp){ll res=1,y=a;while(n>0){if(n&1)res=(res*y)%temp;y=(y*y)%temp;n/=2;}return res%temp;} 

int group[15][15],n;
bool visited[15][15] = {false};

queue<pair<int,int> > toDo;
map<pair<int,int>,int> effect;
void infectHelper(int x, int y, int level){
	if(x < 0 || y < 0 || x >= n || y >= n) return;
	if(visited[x][y] || level < 1) return;
	visited[x][y] = true;

	group[x][y] = level;
	
	if(group[x][y+1] == 1) toDo.push(MP(x,y+1));
	if(group[x][y-1] == 1) toDo.push(MP(x,y-1));
	if(group[x-1][y] == 1) toDo.push(MP(x-1,y));
	if(group[x-1][y+1] == 1) toDo.push(MP(x-1,y+1));
	if(group[x-1][y-1] == 1) toDo.push(MP(x-1,y-1));
	if(group[x+1][y] == 1) toDo.push(MP(x+1,y));
	if(group[x+1][y+1] == 1) toDo.push(MP(x+1,y+1));
	if(group[x+1][y-1] == 1) toDo.push(MP(x+1,y-1));

	effect[MP(x,y+1)] = level-1;
	effect[MP(x,y-1)] = level-1;
	effect[MP(x+1,y)] = level-1;
	effect[MP(x+1,y+1)] = level-1;
	effect[MP(x+1,y-1)] = level-1;
	effect[MP(x-1,y)] = level-1;
	effect[MP(x-1,y+1)] = level-1;
	effect[MP(x-1,y-1)] = level-1;
}

// int findLevel(int x,int y, int tX, int tY){
// 	int level = 0;
// 	int xDist, yDist;
// 	// if(x == tX && y == tY) return 5;
// 	// xDist = abs(x-tX);
// 	// yDist = abs(y-tY);
// 	// return 6-max(xDist,yDist);
// 	pair<int,int> coord = MP(x,y);
// 	return effect[coord];
// }

void infect(int x,int y){
	int i,j;
	toDo.push(MP(x,y));
	
	effect[toDo.front()] = 5;
	pair<int,int> coord;

	while(!toDo.empty()){
		coord = toDo.front();
		toDo.pop();
		infectHelper(coord.first,coord.second,effect[coord]);
	}

	// cout<<"infect\n";
	// REP(i,n){
	// 	REP(j,n){
	// 		cout<<group[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
}

void antidote(int x,int y){
	int i,j;
	REP(i,n){
		REP(j,n){
			if(visited[i][j]) group[i][j] -= 1;
		}
	}
	
	if(x>-1 && y>-1 && x<n+1 && y<n+1 && group[x][y] != 0) group[x][y] = 1;
	if(x>-1 && y+1>-1 && x<n+1 && y+1<n+1 && group[x][y+1] != 0) group[x][y+1] = 1;
	if(x>-1 && y-1>-1 && x<n+1 && y-1<n+1 && group[x][y-1] != 0) group[x][y-1] = 1;
	if(x-1>-1 && y>-1 && x-1<n+1 && y<n+1 && group[x-1][y] != 0) group[x-1][y] = 1;
	if(x-1>-1 && y+1>-1 && x-1<n+1 && y+1<n+1 && group[x-1][y+1] != 0) group[x-1][y+1] = 1;
	if(x-1>-1 && y-1>-1 && x-1<n+1 && y-1<n+1 && group[x-1][y-1] != 0) group[x-1][y-1] = 1;
	if(x+1>-1 && y>-1 && x+1<n+1 && y<n+1 && group[x+1][y] != 0) group[x+1][y] = 1;
	if(x+1>-1 && y+1>-1 && x+1<n+1 && y+1<n+1 && group[x+1][y+1] != 0) group[x+1][y+1] = 1;
	if(x+1>-1 && y-1>-1 && x+1<n+1 && y-1<n+1 && group[x+1][y-1] != 0) group[x+1][y-1] = 1;
}

int main(){
	int i,j,x1,y1,x2,y2;
	SI(n);
	REP(i,n)
		REP(j,n)
			SI(group[i][j]);
	SI(x1); SI(y1);
	SI(x2); SI(y2);
	x1 -= 1;
	x2 -= 1;
	y1 -= 1;
	y2 -= 1;
	infect(x1,y1);
	antidote(x2,y2);
	REP(i, n){
		REP(j, n){
			cout<<group[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}