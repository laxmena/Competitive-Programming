#include <iostream>
#include <cstdio>

#define CELLS 9

using namespace std;

//How to check if an instance of 8 puzzle is solvable?
//http://www.geeksforgeeks.org/check-instance-8-puzzle-solvable/

int findInversionCount(int arr[]){
	int count = 0;
	for(int i=0;i<CELLS-1;i++)
		for(int j=i+1;j<CELLS;j++)
			if(arr[i] && arr[j] && arr[i]>arr[j])
				count++;
	return count;	
}

int main(){
	int invCount;
	printf("Enter Puzzle Board position: \n");
	int board[CELLS];
	for(int i=0;i<CELLS;i++)
		scanf("%d",&board[i]);
	invCount = findInversionCount(board);
	cout << ((invCount%2 == 0)? "Solvable" : "Not Solvable") << "\n";
	return 0;
}