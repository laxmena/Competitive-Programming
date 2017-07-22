#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int convert(string rnumeral){
	stack<int> bin;
	int sum = 0, temp;

	map <char,int> r_to_int;
	r_to_int['I'] = 1;
	r_to_int['V'] = 5;
	r_to_int['X'] = 10;
	r_to_int['L'] = 50;
	r_to_int['C'] = 100;
	r_to_int['D'] = 500;
	r_to_int['M'] = 1000;

	if(r_to_int.find(rnumeral[0]) == r_to_int.end())
		return -1;

	bin.push(r_to_int[rnumeral[0]]);
	
	for(int i=1;i<rnumeral.size();i++){
			if(r_to_int.find(rnumeral[i]) == r_to_int.end())
				return -1;
			if(bin.top() < r_to_int[rnumeral[i]]){
				temp = bin.top();
				bin.pop();
				bin.push(r_to_int[rnumeral[i]] - temp);
			}
			else
				bin.push(r_to_int[rnumeral[i]]);
	}

	while(!bin.empty()){
		sum += bin.top();
		bin.pop();
	}	

	return sum;
}

int main(){
	string roman;
	cin>>roman;
	cout<<convert(roman);
	return 0;
}