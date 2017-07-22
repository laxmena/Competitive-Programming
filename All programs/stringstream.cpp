#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
	string s;
	cin>>s;
	stringstream obj(s);
	int x;
	obj >> x;
	cout << x+5;
	return 0;
}