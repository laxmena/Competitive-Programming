#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main(){
	int n,t,c1,c2,i;
	int meetingPoint = -1;
	vector<int> graph;
	scanf("%d",&n);
	vector<int> visited(n,0);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		graph.push_back(t);
	}
	scanf("%d%d",&c1,&c2);
	int t1=c1, t2=c2;
	while(true){
		if(visited[t1] != 1 && visited[t1] != 2){
			visited[t1] = 1;
			t1 = graph[t1];
		}
		else if(visited[t1] == 2){
			meetingPoint = t1;
			break;
		}
		if(visited[t2] != 2 && visited[t2] != 1){
			visited[t2] = 2;
			t2 = graph[t2];
		}
		else if(visited[t2] == 1){
			meetingPoint = t2;
			break;
		}
		if(visited[t1] == 1 && visited[t2] == 2)
			break;
	}	
	return 0;
}