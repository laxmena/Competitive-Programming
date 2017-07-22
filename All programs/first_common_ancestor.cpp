#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class BinaryTree{
	class Node{
		public:
			int data;
			Node* left;
			Node* right;
			Node* parent;

			Node(int n){
				data = n;
				left = NULL;
				right = NULL;
				parent = NULL;
			}

			void setParent(Node* node){
				parent = node;
			}

			void setLeftChild(Node* node){
				left = node;
			}

			void setRightChild(Node* right){
				right = node;
			}

	}

	Node* root = NULL;
	int size = 0; 
	public:
		BinaryTree(int nodeCount){
			self.size = nodeCount;
		}
		
};

int main(){
	
}