#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class graph{
	private:
		
		class node{
			public:
				int data;
				vector<node> destination;
				node(int data){
					this->data = data;
				}
				void addDestination(node n){
					destination.push_back(n);
				}
				int getDestination(int n){
					return destination[n].data;
				}
		};


		int nodesCount;
		vector<node*> adjList;

	public:
		graph(int n){
			this->nodesCount = n;
			for(int i=0;i<nodesCount;i++){
				node* a = new node(i);
				adjList.push_back(a);
			}
		}

		void addEdge(int src,int dest){
			adjList[src]->addDestination(dest);
		}

		void printAdjList(){
			for(int i=0;i<nodesCount;i++){
				cout<<i<<" -> ";
				for(int j=0;j<adjList[i]->destination.size();j++){
					cout<<adjList[i]->getDestination(j)<<" ";
				}
				cout<<endl;
			}
		}
};

int main(){
	graph g(5);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.addEdge(2,2);
	g.addEdge(3,2);
	g.addEdge(4,3);
	g.addEdge(4,2);
	g.addEdge(3,3);
	g.printAdjList();
	return 0;
}