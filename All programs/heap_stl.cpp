#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int arr[] = {5,10,15,12,17,10,20};

	vector<int> v (arr, arr+sizeof(arr)/sizeof(arr[0]));
	vector<int> :: iterator it;
	
	make_heap(v.begin(), v.end());
	for(it = v.begin(); it != v.end(); it++){
		cout<<*it<<" ";
	}
	cout << "\n\n";

	v.push_back(18);
	push_heap(v.begin(),v.end());
	for(it = v.begin(); it != v.end(); it++){
		cout<<*it<<" ";
	}
	cout << "\n\n";

	cout<<"Poping!";

	cout<<v.front()<<" ";
	pop_heap(v.begin(), v.end());

	cout<<"\nAfter popping: \n";
	for(it = v.begin(); it != v.end(); it++){
		cout<<*it<<" ";
	}
	cout << "\n\n";

	cout<<"Sorting\n";
	sort_heap(v.begin(), v.end());
	for(it = v.begin(); it != v.end(); it++){
		cout<<*it<<" ";
	}
	cout << "\n\n";

	return 0;
}