#include<iostream>

using namespace std;

class list{
	private:
	class node{
		public:
		int data;
		node* next;
		node(int data){
			this->data = data;
			this->next = NULL;
		}
	};	
	node *root;
	int length;
	public:
		list(){
			root = NULL;
			length = 0;
		}
		void insert(int data){
			node* temp = root;
			if(root==NULL)
				root = new node(data);
			else{
				while(temp->next != NULL)
					temp = temp->next;
				temp->next = new node(data);
			}
			length++;
		}
		
		void insertAt(int data,int position){
			node* n = new node(data);
			if(position==0){
				n->next = root;
				root = n;
			}
			else{
				node* temp = root;
				while(position-->1)
					temp = temp->next;
				n->next = temp->next;
				temp->next = n;
			}
			length++;
		}
		int remove(){
			node* temp = root;
			if(temp == NULL)
				return -1;
			else if(temp->next == NULL){
				root = NULL;
				return temp->data;
			}
			else{
				int d;
				while(temp->next->next != NULL)
					temp = temp->next;
				d = temp->next->data;
				temp->next = NULL;
				return d;
			}
			length--;
		}
		int retrieve(int pos){
			node* temp=root;
			if(pos>=length)
				return -1;
			while(pos-->0)
				temp = temp->next;
			return temp->data;
		}
		bool isEmpty(){
			return length==0; 
		}
		int len(){
			return length;
		}
};

int main(){
	list l;
	l.insert(1);
	l.insert(5);
	l.insert(3);
	l.insertAt(2,1);
	int t=l.len();
	for(int i=0;i<t;i++)
		cout<<l.retrieve(i)<<endl;
	cout<<"Popping!"<<endl;
	for(int i=0;i<t;i++)
		cout<<l.remove()<<endl;
	return 0;
}