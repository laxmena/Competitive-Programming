#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int n,i;
	cin>>s>>n;
	int len = s.size();
	string substr[len];
	substr[len-1] = s[len-1];
	for(i=len-2; i >= 0; i--)
		substr[i] = s[i] + substr[i+1];
	sort(substr, substr+len);
	cout<<endl<<substr[n-1];
	return 0;
}