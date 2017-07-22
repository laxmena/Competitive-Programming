
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


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define SI(t) scanf("%d",&t)
#define SL(t) scanf("%ld",&t)
#define SLL(t) scanf("%lld",&t)
#define SC(t) scanf("%c",&t)
#define SS(t) scanf("%s",t)
#define SF(t) scanf("%f",&t)
#define SLF(t) scanf("%lf",&t)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define MP make_pair
#define PB push_back
#define MAX (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

const double pi=acos(-1.0);
typedef vector<int> VI;
typedef vector<string> VS;
typedef set<int> SETI;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;

//http://www.geeksforgeeks.org/median-of-two-sorted-arrays/

int findMedian(VI v1, VI v2){
	int m1,m2,s1,s2,i;
	if(v1.size() < 0)
		return -1;
	if(v1.size() < 3){
		if(v1.size() == 1)
			return (v1[0]+v2[0])/2;
		else
			return (max(v1[0],v2[0])+min(v1[1],v2[1]))/2;
	}
	s1 = v1.size()/2;
	s2 = v2.size()/2;
	if(v1.size()%2 == 0)
		m1 = (v1[s1-1]+v1[s1])/2;
	else
		m1 = v1[s1];
	if(v2.size()%2 == 0)
		m2 = (v2[s2-1]+v2[s2])/2;
	else
		m2 = v2[s2];

	//***************************************
	VI temp1,temp2;
	if(m1<m2){
		for(i=s1;i<v1.size();i++)
			temp1.PB(v1[i]);
		for(i=0;i<=s2;i++)
			temp2.PB(v2[i]);
	}
	else{
		for(i=s2;i<v2.size();i++)
			temp2.PB(v2[i]);
		for(i=0;i<=s1;i++)
			temp1.PB(v1[i]);
	}
	//***************************************
	if(temp1.size() != temp2.size())
		return -1;
	return findMedian(temp1,temp2);
}

int main(){
	int n,t,i,median;
	VI v1,v2;
	SI(n);
	for(i=0;i<n;i++){
		SI(t);
		v1.PB(t);
	}
	for(i=0;i<n;i++){
		SI(t);
		v2.PB(t);
	}
	median = findMedian(v1,v2);
	cout<<median<<endl;
	return 0;
}

/*
Sample Input:
	5
	1 12 15 26 38
	2 13 17 30 45
Sample Output:
	16
*/