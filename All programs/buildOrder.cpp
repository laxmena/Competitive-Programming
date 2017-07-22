#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <map
>#include <cstdio>

using namespace std;

class Node{
	char data;
	int dependency;
	list<Node*> children; 
	public:
		Node(int data){
			this.data = data;
			dependency = 0;
		}
		void incDependency(){
			dependency++;
		}
		void decDependency(){
			dependency--;
		}
		char getData(){
			return data;
		}
		int getDependency(){
			return dependency;
		}
		void addChild(Node* child){
			children.push_back(child);
		}
		list<Node*> getChildren(){
			return children;
		}
};

class Graph{
	int nodes;
	list<Node*> adjList;
	vector<char> buildOrder;
	list<Node*> processQueue;
	map<char,Node*> hash;
	public:
		Graph(int n){
			this.nodes = n;
		} 
		void create(char data){
			Node n1(data);
			hash[data] = &n1;
		}
		void addEdge(char source, char destination){
			Node* n1 = getOrCreateNode(source);
			Node* n2 = getOrCreateNode(destination);
			n1.addChild(n2);
			n2.incDependency();
		}
		Node* getOrCreateNode(char data){
			if(hash.find(data) == hash.end())
				create(data);
			return hash[data];
		}
		void generateBuildOrder(){
			addZeroDependencies();

			while(buildOrder.size() < nodes && processQueue.size() > 0){
				list<Node*> :: iterator it;
				list<Node*> :: iterator innerIt;
				list<Node*> childList;
				for(it = processQueue.begin(); it != processQueue.end(); it++){
					childList = (*it)->getChildren();
					for(innerIt = childList.begin(); innerIt != childList.end(); it++){
						*innerIt->decDependency();
					}
					buildOrder.push_back((*it)->data);
				}
				addZeroDependencies();
			}
		}

		void addZeroDependencies(){
			map<char,Node*> :: iterator it;
			for(it = hash.begin(); it!=hash.end(); it++){
				if((*it).getDependency() == 0){
					processQueue.push_back(it);
					hash.erase(*it);
				}
			}
		}
};


int main(){

	return 0;
}