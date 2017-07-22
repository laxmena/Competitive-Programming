#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//Approach 1
int main(){
	long int n,t,i,queries;
	scanf("%ld",&n);
	vector <int> boxes;
	for(i=0;i<n;i++){
		scanf("%ld",&t);
		if(i>0)
			boxes.push_back(boxes[i-1]+t);
		else
			boxes.push_back(t);
	}
	scanf("%ld",&queries);
	while(queries --> 0){
		scanf("%ld",&t);
		vector<int> :: iterator it = lower_bound(boxes.begin(),boxes.end(),t);
		cout<<it - boxes.begin() + 1<<endl;
	}
	return 0;
}