#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class node{
	private:
		int data;
		node* left;
		node* right;
	public:
		node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
		int get(){
			return data;
		}
		node* getLeft(){
			return left;
		}
		node* getRight(){
			return right;
		}
		void setLeft(node* link){
			left = link;
		}
		void setRight(node* link){
			right = link;
		}
};

void buildTree(vector<int> arr, int start, int end){
		if(start>end)
			return NULL;
		int i = max(arr,start,end);
		cout<<i;
}

int main(){
	int n,t;
	cin>>n;
	vector <int> inorder;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		inorder.push_back(t);
	}
	buildTree(inorder,0,inorder.size()-1);
	return 0;
}