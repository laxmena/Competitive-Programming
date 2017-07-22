#include <string>
#include <iostream>
#include <sstream>


using namespace std;

int main(){
	string input;
	int result;
	cin>>input;
	stringstream convert(input);
	convert >> result;
	cout << result;
	return 0;
}