#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
	vector< vector<int> > matrix;
	int count = 0;
	int temp, t, n;

	scanf("%d",&t);
	while(t-->0){
		
		count = 0;

		scanf("%d",&n);
		for(int i=0;i<n;i++){
			vector<int> arr;
			for(int j=0;j<n;j++){
				scanf("%d",&temp);
				arr.push_back(temp);
			}
			matrix.push_back(arr);
		}


		for(int i=1; i<n; i++)
		for(int j=1; j<n; j++){
				for(int p=0;p<=i;p++)
				for(int q=0;q<=j;q++){
					if(matrix[p][q] > matrix[i][j]){
						count++;
					}
				}
		}

		cout << count <<endl;
	}


	return 0;
}