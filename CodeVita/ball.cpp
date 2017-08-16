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

int n;
int grid[20][20];

//Determine the shorted path with minimum barriers
VI determinePath(VI up, VI down, VI right, VI left){
	vector< VI > possible;
	possible.PB(up);
	possible.PB(down);
	possible.PB(right);
	possible.PB(left);
	sort(all(possible));
	return possible[0];
}

string direction[] = {"up","down","right","left"};
// direction => "up","down","right","left"
VI findPath(int x2,int y2, int x1, int y1,int dir){
	int pathLen = 0;
	int barrierCount = 0;

	while((x1!=x2 || y1!=y2) && (x2>-1 && y2>-1 && x2<n && y2<n)){
		if(grid[x2][y2] == 1){
			//Up -> Right
			if(dir == 0) { y2 += 1; dir = 2; }
			//Down -> Left
			else if(dir == 1){ y2 -= 1; dir = 3; }
			//Right -> Up
			else if(dir == 2){ x2 -= 1; dir = 0; }
			//Left -> Down
			else{ x2 += 1; dir = 1; }
			//Increment Barrier count
			barrierCount += 1;
		}
		else if(grid[x2][y2] == 2){
			//Up -> Left
			if(dir == 0){ y2 -= 1; dir = 3; }
			//Down -> Right
			else if(dir == 1){ y2 += 1; dir = 2; }
			//Right -> Down
			else if(dir == 2){ x2 += 1; dir = 1; }
			//Left -> Up
			else{ x2 -= 1; dir = 0; }
			//Increment Barrier Count
			barrierCount += 1;
		}
		else{
			//Move Up
			if(dir == 0) x2 -= 1;
			//Move Down
			else if(dir == 1) x2 += 1;
			//Move right
			else if(dir == 2) y2 += 1;
			//Move Left
			else y2 -= 1;
		}
		pathLen += 1;
		// cout<<direction[dir]<<" ";
	}
	// cout<<endl;
	if(x1 != x2 || y1 != y2) pathLen = MAX;
	VI result;
	result.PB(pathLen); result.PB(barrierCount);
	return result;
}

//Wrapper function
VI findPath(int x1, int y1, int x2, int y2){
	VI upPath, downPath, leftPath, rightPath;
	
	// cout<<"up::\n";
	upPath = findPath(x2,y2,x1,y1,0);
	// cout<<"down::\n";
	downPath = findPath(x2,y2,x1,y1,1);
	// cout<<"right::\n";
	rightPath = findPath(x2,y2,x1,y1,2);
	// cout<<"left::\n";
	leftPath = findPath(x2,y2,x1,y1,3);

	VI path = determinePath(upPath, downPath, rightPath, leftPath);

	return path;
}

int main(){
	int x1,y1,x2,y2,i,j;
	VI path;
	SI(n);
	SI(x1);SI(y1);
	SI(x2);SI(y2);
	REP(i,n)
		REP(j,n)
			SI(grid[i][j]);
	grid[x2][y2] = 0;

	path = findPath(x1,y1,x2,y2);
	if(path[0] == MAX) path[0] = -1;
	cout<<path[0]<<" "<<path[1];
	return 0;
}

/*
5
0 0
4 4
2 0 0 0 0
2 2 0 0 0
0 2 2 0 0
0 0 2 2 0
0 0 0 2 2 

4
0 3
3 2
0 0 1 0
1 0 1 1
0 0 0 0
2 0 0 0

*/