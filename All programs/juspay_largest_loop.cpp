#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class graph{
	class node{
		public:
			int next;
			node(int dest){
				next = dest;
			}
	};
	vector<int> cyclePath;
	vector<bool> visited;
	vector<node*> adjList;
	int graphNodes;
	public:
		int cycleLength;
		graph(int n){
			graphNodes = n;
			vector<bool> t1 (n,false);
			visited = t1;
			vector<node*> t2 (n,NULL);
			adjList = t2;
			cycleLength = -1;
		}
		void addEdge(int src,int dest){
			adjList[src] = new node(dest);
		}
		bool isVisited(int node){
			return visited[node] == true;
		}

		void printAdjList(){
			for(int i=0;i<graphNodes;i++){
				cout<<i<<" -> "<<adjList[i]->next<<" "<<visited[i]<<endl;
			}
		}

		int traceCycle(int start){
			int count = 1;
			int nodePos = adjList[start]->next;
			while(nodePos != start){
				nodePos = adjList[nodePos]->next;
				count++;
			}
			cout<<"traceCycle: "<<count<<endl;
			return count;
		}

		void findLargestCycle(){
			for(int i=0;i<graphNodes;i++){
				int j = i;
				if(!visited[j]){
					while(!visited[j] && adjList[j]->next!=-1){
						visited[j] = true;
						j = adjList[j]->next;
					}				
				if(j == i && adjList[i]->next!=-1 ){
					int temp = traceCycle(j);
					if(temp>cycleLength)
						cycleLength = temp;
				}
				}
			}
		}
};

int main(){
	int n,t;
	cin>>n;
	graph g(n);
	for(int i=0;i<n;i++){
		cin>>t;
		g.addEdge(i,t);
	}
	// g.printAdjList();
	g.findLargestCycle();
	cout<<"Count: "<<g.cycleLength;
	return 0;
}

// 23
// 4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
