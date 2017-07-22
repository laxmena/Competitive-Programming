//https://www.codechef.com/problems/UNIVERSE
#include <bits/stdc++.h>
#include <tuple>

using namespace std;

class Graph{
	int universeCount;
	int planetsCount;
	public:
		//Planet class, which contains path information to other Plaanets
		class Planet{
		public:
			int universe;
			int planet;
			list<Planet> path;

			//Constructor to create a new Planet
			Planet(int universeNum, int planetNum){
				universe = universeNum;
				planet = planetNum;
			}

			//Add Path to another Planet
			addPath(Planet target){
				path.push_back(target);
			}
		};

		//tuple (Universe, Planet) => In case of records
		//tuple (from, to)         => In case of edges
		tuple<int,int> pair;
		map<pair, Planet> records;

		//multiverse[universe][planet]
		list<list<Planet> > multiverse;

		//Edge
		list<pair> edges;

		//Constructor to create a new graph
		Graph(int planets){
			planetsCount = planets;
			universeCount = 0;
		}

		//Create a new universe
		void makeUniverse(){
			list<Planet> universe;

			//Calculate universe id by incrementing the current number of universe
			int uid = universeCount + 1;	

			//Add planets to the universe		
			for(int pid=0;pid<planetsCount;pid++){
				Planet planet(uid,pid);
				universe.push_back(planet);
				records[make_tuple(uid,pid)] = planet;
			}

			//add the newly created universe into the multiverse
			multiverse.push_back(universe);

			//Increment universeCount
			universeCount += 1;
		}

		void createEdge(int fromP, int toP){
			tuple<int,int> edge;
			edge = make_tuple(fromP, toP);
			edges.push_back(edge);
		}

		void addTeleport(int fromP, int fromU, int toP, int toU){

		}
};

int main(){
	int m,n,q;
	int i;
	int fromP,toP,fromU,toU;
	scanf("%d%d%d",&m,&n,&q);

	Graph graph(n);

	for(i=1;i<n;i++){
		scanf("%d%d",&fromP,&toP);
		graph.createEdge(fromP,toP);
	}
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&fromP,&fromU,&toP,&toU);
		graph.addTeleport(fromP,fromU,toP,toU);
	}
	return 0;
}