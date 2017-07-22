#include <bits/stdc++.h>

using namespace std;
set<int> dict;

void findSequence(){
	set<int> :: reverse_iterator it;
	bool flag;
	int diff;
	dict.insert(1);
	dict.insert(2);
	for(int i=3;i<501;i++){
		flag = true;
		for(it = dict.rbegin(); it!=dict.rend(); it++){
			diff = i-*it;
			if(diff < 0)
				break;
			if(dict.find(diff) != dict.end()){
				flag = false;
				break;
			}
		}
		if(flag)
			dict.insert(i);
	}
}

int main(){
	int t, i, n;
	scanf("%d",&t);
	findSequence();
	while(t--){
		scanf("%d",&n);
		set<int> :: iterator it = dict.begin();
		while(n-->0){
			cout<<*it<<" ";
			*it++;
		}
		cout<<endl;
	}
	return 0;
}