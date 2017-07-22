#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int deletionCount(string a, string b){
	vector<int> frequency1(26,0);
	vector<int> frequency2(26,0);
	int count = 0, i;
	for(i=0;i<a.size();i++)
		frequency1[a[i]-'a'] += 1;

	for(i=0;i<b.size();i++)
		frequency2[b[i]-'a'] += 1;

	for(i=0;i<26;i++)
		count += abs(frequency1[i]-frequency2[i]);

	return count;
}

int main(){
	string a,b;
	cin>>a>>b;
	cout<<deletionCount(a,b);
	return 0;
}