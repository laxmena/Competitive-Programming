#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

//Find the Number of Triangles in an Undirected Graph
//Link: http://www.geeksforgeeks.org/number-of-triangles-in-a-undirected-graph/

void matrixMultiply(vector< vector<int> > graph1,
                    vector< vector<int> > graph2,
                    vector< vector<int> > &result){
	int i,j,k;
	for(i=0;i<graph1.size();i++)
		for(j=0;j<graph2.size();j++)
			for(k=0;k<graph1.size();k++){
				result[i][j] += graph1[i][k]*graph2[k][j];
			}
}

int trace(vector< vector<int> > matrix){
	int trace = 0;
	for(int i=0;i<matrix.size();i++)
		trace += matrix[i][i];
	return trace;
}

int main(){
	int n,i,j,temp;
	scanf("%d",&n);
	vector< vector<int> > adjMatrix(n, vector<int>(n,0));
	vector< vector<int> > matrixSq(n, vector<int>(n,0));
	vector< vector<int> > matrixCube(n, vector<int>(n,0));
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&temp);
			adjMatrix[i][j] =temp;
		}
	}

	matrixMultiply(adjMatrix, adjMatrix, matrixSq);
	matrixMultiply(matrixSq, adjMatrix, matrixCube);

	cout << trace(matrixCube)/6<< endl;
	return 0;
}