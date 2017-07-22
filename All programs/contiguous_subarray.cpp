#include <iostream>
#include <cstdio>
#include <vector> 

using namespace std;

int main(){
	int t,n,sum,temp;
	scanf("%d",&t);

	while(t-->0){
	
		vector<int> array;
		int arr_sum,start,end;
		scanf("%d%d",&n,&sum);
	
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			array.push_back(temp);
		}
	
		start = 0;
		arr_sum = 0;
	
		for(int i=start;i<n;i++){
			arr_sum += array[i];			
	
			while(arr_sum > sum){
				arr_sum -= array[start];
				start++	;
			}
			if(arr_sum == sum){
				cout <<start+1<<" "<<i+1<<endl;
				break;
			}
			if(i==n-1)
				cout<<"-1\n";
		}
	}
	return 0;
}