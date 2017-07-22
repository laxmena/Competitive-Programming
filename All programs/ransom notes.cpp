#include <bits/stdc++.h>

using namespace std;

int main(){
	int i;
	map <string,int> dict;
	string temp;
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	for(i=0;i<n1;i++){
		cin>>temp;
		if(dict.find(temp) != dict.end()){
			dict[temp] += 1;
		}
		else
			dict[temp] = 1;
	}
	for(i=0;i<n2;i++){
		cin>>temp;
		if(dict.find(temp) != dict.end() && dict[temp] > 0){
			dict[temp] -= 1;
		}
		else{
			cout <<"No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}