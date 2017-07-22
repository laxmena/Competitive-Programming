#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map <int,long int> dict;

long int catalanNumber(int num){
	map <int,long int> :: iterator it;
	it = dict.find(num);
	if(it != dict.end())
		return dict[num];
	long int result = 0, temp1, temp2;
	for(int i=0;i<num;i++){
		temp2 = catalanNumber(i);
		temp1 = catalanNumber(num-i-1);
		result += (temp1*temp2);
	}
	dict[num] = result;
	return dict[num];
}


int main(){
	int n;
	int t;
	cin>>t;
	dict.insert(pair<int,long int>(0,1));
	dict.insert(pair<int,long int>(1,1));
	cout<<"Dict[0] = "<<dict[0]<<" dict[1]"<<dict[1]<<endl;
	while(t-->0){
		cout<<"Number of nodes in a Binary Tree: ";
		cin>>n;
		cout<<"Enumeration of Binary Tree: "<<catalanNumber(n) << endl;
	}
	return 0;
}