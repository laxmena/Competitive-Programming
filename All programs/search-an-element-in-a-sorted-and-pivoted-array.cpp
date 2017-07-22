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

//http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

int binarySearch(VI arr, int start, int end, int search){
	int mid = (start + end)/2;
	if(start>end){
		return -1;
	}
	if(arr[mid] == search)
		return mid;
	if(arr[mid] < search)
		return binarySearch(arr,mid+1,end,search);
	else
		return binarySearch(arr,start,mid,search);
}

int main(){
	int n,i,t,pivot,search;
	VI arr;
	SI(n);
	for(i=0;i<n;i++){
		SI(t);
		if(i>0 && arr[i-1]>t)
			pivot = i-1;
		arr.PB(t);
	}
	SI(search);
	if(search > arr[0])
		cout<<binarySearch(arr,0,pivot,search);
	else
		cout<<binarySearch(arr,pivot,arr.size()-1,search);
	return 0;
}