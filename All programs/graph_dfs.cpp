#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

class Node{
	public:
		int data;
		list<Node*> next;	

		Node(int val){
			data = val;
		}
};

class Graph{
	int nodes;
	list<Node*> adjList;
	
	public:
		Graph(int count){
			nodes = count;
		}
		void addNode(int data){
			
		}
};

int main(){

	return 0;
}