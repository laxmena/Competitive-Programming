#include <bits/stdc++.h>

using namespace std;

//Project node defenition
class project{
	public:
		string name;
		int dependencies = 0;
		vector <project*> child;

		//Constructor
		project(string name){
			this.name = name;
		}
};

//Build Order - Final order to build the projects
vector<project*> buildOrder;

//Process Queue - Nodes to process next
list<project*> processQueue;

//projecMap - Maps project name, wit its nodes
map <string, project*> projectMap;

//Graph Defenition
class Graph{
	vector <project> adjList;
	public:
		int nodeCount;
		Graph(int n){
			nodeCount = n;
		}

		void addProject(string name){
			project p = new project(name);
			adjList.push_back(p);
			projectMap.insert(name,p);
		}

		project* getOrCreateProject(string project){
			if(projectMap.find(project) == projectMap.end())
				addProject(string);
			return projectMap[project];
		}

		void addEdge(string parent, string child){
			p1 = getOrCreateProject(parent);
			p2 = getOrCreateProject(child);
			p2->dependencies += 1;
			p1->child.push_back(p2);
		}
};

void addZeroDependencies(){
	map<string, project*> :: iterator it;
	for(it = projectMap.begin(); it != projectMap.end(); it++){
		if((*it)->dependencies == 0)
			processQueue.push_back(*it);
	}
}

bool generateBuildOrder(Graph g){
	while(buildOrder.size() < g.nodeCount){
		addZeroDependencies();
		if(processQueue.size() == 0)
			return false;
		list <project*> :: iterator it;
		vector <project*> :: iterator projIt;
		for(it = processQueue.begin(); it != processQueue.end(); it++){
			for(projIt = (*it)->child.begin(); projIt != (*it)->child.end(); projIt++){
				(*projIt) -> dependencies -= 1;
			}
		}
		processQueue.empty();
		addZeroDependencies();
	}
}

//Cracking the coding interview - Build Order
int main(){
	int n,edges;
	string name,parent,child;
	scanf("%d",&n);
	Graph g(n);
	for(int i=0;i<n;i++){
		cin>>name;
		g.addProject(name);
	}
	scanf("%d",&edges);
	for(int i=0;i<edges;i++){
		cin>>parent>>child;
		g.addEdge(parent, child);
	}
	generateBuildOrder(g);

	//Display Build Order
	vector<project*> :: iterator it;
	for(it = buildOrder.begin(); it != buildOrder.end(); it++)
		cout<<(*it)->name;
	return 0;
}