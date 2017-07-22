#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	int i,t;
	string input;
	stack<char> bin;
	while(t-->0){
		cin>>input;
		for(i=0;i<input.size(); i++)
			bin.push(input[i]);
		for(i=0;i<input.size();i++){
			cout << bin.top();
			bin.pop();
		}
		cout<<endl;
		bin.empty();
	}
	return 0;
}