#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
#include <cstdlib>

#define PB push_back

using namespace std;

int main(){
	vector<int> v1;
	set<int> v2;
	int n1,n2,t,i;
	int sum1 = 0, sum2 = 0;

	//Get input
	scanf("%d",&n1);
	for(i=0;i<n1;i++){
		scanf("%d",&t);
		sum1 += t;
		v1.PB(t);
	}
	scanf("%d",&n2);
	for(i=0;i<n2;i++){
		scanf("%d",&t);
		sum2 += t;
		v2.insert(t);
	}

	//Calculate differnce
	int diff = abs(sum1 - sum2)/2;

	//Find pair
	for(i=0;i<v1.size();i++){
		if( v2.find(v1[i]+diff) != v2.end()){
			cout<<v1[i]<<" "<<v1[i]+diff;
			break;
		}
	}
	return 0;	
}