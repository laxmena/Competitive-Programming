#include <iostream>

using namespace std;

int main(){
	int arr[] = {1,2,3,4,54, 6,7,8,9,0};
	int size = *(&arr+1) - arr;
	cout<<"Size of the array is "<<size<<endl;
	return 0;
}