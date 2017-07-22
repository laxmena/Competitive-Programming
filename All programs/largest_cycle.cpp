#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int traceFrom(vector<int> graph, int t){
	int temp = t, count=0;
	while(graph[temp] != t){
		count++;
		temp = graph[temp];
		cout<<count<<endl;
	}
	return count;
}

int findLargestCycle(vector<int> graph, int n){
	vector<bool> visited(n,false);
	int f,l = 0,t;
	for(int i=0;i<n;i++){
		t = i;
		f = 0;
		while(!visited[t]){
			visited[t] = true;
			t = graph[i];
			f = 1;
		}
		if(!visited[t] && f){
			cout<<t<<endl;
			int len = traceFrom(graph,t);
			if(len>l) l = len;
		}
	}
	return l;
}

int main(){
	int n,t,i;
	vector<int> graph;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		graph.push_back(t);
	}
	int l = findLargestCycle(graph,n);
	cout<<l<<endl;
	return 0;
}