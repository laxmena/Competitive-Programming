#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int t,n,temp,i;
	cin>>t;
	while(t-->0){
		cin>>n;
		int right_sum = 0, left_sum = 0;
		
		vector<int> array;
		for(i=0;i<n;i++){
			cin>>temp;
			array.push_back(temp);
			right_sum += temp;
		}

		if(n == 1) cout<<1;
		
		right_sum -= array[0];
		for(i=1;i<n-1;i++){
			if(left_sum < right_sum){
				left_sum += array[i-1];
				right_sum -= array[i];
			}
			if(right_sum == left_sum){
				cout<<i+1;
				break;
			}
		}
		if(i==n-1){
			cout<<-1;
			break;
		}
		cout<<"\n";
	}
	return 0;
}