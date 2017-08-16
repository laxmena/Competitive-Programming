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

int grid[20][20]= {0};
vector< VI > adjacencyNodes(400);

int main(){
	int size,i,j,Hfrom,Vfrom;
	SI(size);
	REP(i,size)
		REP(j,size)
			SI(grid[i][j]);

	REP(i,size){
		Hfrom = -1;
		Vfrom = -1;
		REP(j,size){
			//Horizontal
			if(Hfrom == -1 && grid[i][j] == 1) Hfrom = grid[i][j];
			else if(grid[i][j] == 1){ adjacencyNodes[Hfrom].PB(grid[i][j]);
									  adjacencyNodes[grid[i][j]].PB(Hfrom);
									  Hfrom = grid[i][j];}
			//Vertical
			if(Vfrom == -1 && grid[j][i] == 1) Vfrom = grid[j][i];
			else if(grid[j][i] == 1){ adjacencyNodes[Hfrom].PB(grid[j][i]);
									  adjacencyNodes[grid[j][i]].PB(Hfrom);
									  Hfrom = grid[j][i];}
		}
	}

	int startX,startY,endX,endY;
	VI :: iterator it;
	int node;

	SI(startX); SI(startY);
	SI(endX); SI(endY);

	QI bfsQ;
	bfsQ.push(startX*size + startY);

	int destination = endX*size + endY;

	while(!bfsQ.empty()){
		node = bfsQ.front();
		cout<<node<<" ";
		bfsQ.pop();
		if(node == destination) {
			cout<<"Path available";
			break;
		}
		FOREACH(it,adjacencyNodes[node]){
			bfsQ.push(*it);
		}
	}

	return 0;
}