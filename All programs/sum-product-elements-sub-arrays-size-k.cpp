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

//http://www.geeksforgeeks.org/sum-product-elements-sub-arrays-size-k/
int main(){
	int n,sum=0,prod=1,i;
	SI(n);
	int temp,t,k;
	SI(k);
	list<int> window;
	for(i=0;i<n;i++){
		SI(t);
		prod *= t;
		window.PB(t);
		if(i==(k-1))
			sum = prod;
		if(window.size()>k){
			temp = window.front();
			window.pop_front();
			prod = prod/temp;
			sum = sum + prod;
		}
	}
	cout<<sum;
	return 0;
}

/*
6
3
1 2 3 4 5 6
*/