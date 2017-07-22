#include<iostream>
#include<vector>

using namespace std;


class tree{
	class node{
		public:
		int data;
		node* leftNode;
		node* rightNode;
		node(int data){
			this->data = data;
		}
	};
	public:
		node* root;
		tree(int rootData){
			root = new node(rootData);
		}
		void insert(int data){
			node* temp = root;
			while(true){
				if(data>temp->data){
					if(temp->rightNode == NULL){
						temp->rightNode = new node(data);
						break;
					}
					temp = temp->rightNode;
				}
				else{
					if(temp->leftNode == NULL){
						temp->leftNode = new node(data);
						break;
					}
					temp = temp->leftNode;
				}
			}
		}
		void printInfix(node* r){
			if(r == NULL)
				return;
			printInfix(r->leftNode);
			cout<<r->data<<" ";
			printInfix(r->rightNode);
		}
};


int main(){
	tree t(5);
	t.insert(3);
	t.insert(6);
	t.insert(9);
	t.insert(100);
	t.insert(5);
	t.insert(18);
	t.insert(2);
	t.insert(-3);
	t.printInfix(t.root);
	return 0;
}