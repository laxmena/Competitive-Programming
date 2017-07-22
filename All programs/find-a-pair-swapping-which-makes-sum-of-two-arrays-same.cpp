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

//http://www.geeksforgeeks.org/find-a-pair-swapping-which-makes-sum-of-two-arrays-same/

int main(){
	int n,m,s1,s2,t,i,temp,diff;
	SETI arr1;
	VI arr2;
	s1 = 0;
	s2 = 0;
	SI(n);
	for(i=0;i<n;i++){
		SI(t);
		arr1.insert(t);
		s1 += t;
	}
	SI(m);
	for(i=0;i<m;i++){
		SI(t);
		arr2.PB(t);
		s2 += t;
	}
	diff = abs(s1-s2);
	for(i=0;i<arr2.size();i++){
		temp = diff-arr2[i];
		int chk1 = s1 - temp + arr2[i];
		int chk2 = s2 - arr2[i] + temp;
		if(arr1.find(temp) != arr1.end() && chk1 == chk2){
			cout<<temp<<" "<<arr2[i]<<endl;
			break;
		}
	}	
	return 0;
}