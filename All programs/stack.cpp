#include<iostream>
#include<cstdio>

using namespace std;

class stack{
	class node{
		private:
			int data;
			node* next = NULL;
		public:
			node(int d,node* n){
				this->data = d;
				this->next = n;
			}
			int getData(){
				return this->data;
			}
			node* getNext(){
				return this->next;
			}
	};
	int size;
	node* top = NLUL;

	public:
		stack(){
			size = 0;
		}
		void push(int data){
			node* n = new node(data,top);
			top = n;
			size++;
		}
		int pop(){
			node* n = top;
			if(size==0)
				return -1;
			top = top->getNext();
			return n->getData();
			size--;
		}
		bool isEmpty(){
			return size<=0;
		}
};

int main(){
	return 0;
}