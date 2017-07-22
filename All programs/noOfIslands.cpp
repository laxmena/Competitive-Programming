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


vector < vector<int> > graph;
vector< vector<bool> > visited;

bool isSafe(int row, int col){

	return ((row >= 0) &&
			(col >= 0) &&
			(row < graph.size()) &&
			(col < graph[0].size()) &&
			(graph[row][col] && !visited[row][col]));
}

void DFS(int row, int col){
	int nearRow[] = {-1,-1,-1, 0, 0, 1, 1, 1};
	int nearCol[] = {-1, 0, 1,-1, 1,-1, 0, 1};
	
	visited[row][col] = true;

	for(int k=0;k<8;k++){
		if(isSafe(row+nearRow[k], col+nearCol[k]))
			DFS(row+nearRow[k], col+nearCol[k]);
	}
}

int countIslands(){
	int count = 0;
	for(int i=0;i < graph.size();i++){
		for(int j=0;j < graph[0].size();j++){
			if(graph[i][j] && !visited[i][j]){
				DFS(i,j);
				count++;
			}
		}
	}
	return count;
}

int main(){
	int n,i,j,t; 
	SI(n);
	for(i=0;i<n;i++){
		vector<int> temp;
		vector<bool> tempV;
		for(j=0;j<n;j++){
			SI(t);
			temp.PB(t);
			tempV.PB(false);
		}
		graph.PB(temp);
		visited.PB(tempV);
	}

	// for(i=0;i<n;i++){
	// 	for(j=0;j<n;j++){
	// 		cout <<graph[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	cout << countIslands();
	return 0;
}