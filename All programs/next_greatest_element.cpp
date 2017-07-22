#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <cstdio>

#define PB push_back

using namespace std;

int main(){
	stack<int> bin;
	vector<int> order;
	map<int,int> next;

	int n,t,i,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		order.PB(t);
		next[t] = -1;

		if(bin.size() == 0)
			bin.push(t);
		else if(bin.top() < t){
			while(bin.size() > 0 && bin.top() < t){
				temp = bin.top();
				bin.pop();
				next[temp] = t;
			}
			bin.push(t);
		}
		else
			bin.push(t);
	}

	for(i=0;i<n;i++){
		cout<<order[i]<<" -> "<< next[order[i]] <<endl;
	}
	return 0;
}
