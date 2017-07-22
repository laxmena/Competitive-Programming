#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n,t;
	int max = 0;
	int count = 0;
	cin>>n;
	vector<int> next(n);
	for(int i=0;i<n;i++){
		cin>>t;
		next[i] = t;
	}	
	sort(next.begin(),next.end());
	t = next[0];
	for(int i=0;i<n;i++){
		while(next[i] == t && i<n){
			i++;
			count++;
		}
		if(count>max)
			max = count;
		t = next[i];
		count = 1;
	}
	cout<<max;
	return 0;
}