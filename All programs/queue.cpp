#include<iostream>

using namespace std;

class queue{
private:
	class node{
		public:
			int data;
			node *next;
				node(int data,node* next){
					this->data = data;
					this->next = next;
				}
	};
	node *front,*last;
	int size;
	public:
		queue(){
			front = NULL;
			last=NULL;
			size = 0;
		}
		void enque(int data){
			node *temp= new node(data,NULL);
			if(front == NULL)
				front = temp;
			if(last==NULL)
				last = front;
			else{
				last->next = temp;
				last = temp;
			}
			size++;
		}
		int deque(){
			node* temp = front;
			if(temp==NULL)
				return -1;
			front = temp->next;
			size--;
			return temp->data;
		}
		bool isEmpty(){
			return size==0;
		}
};
int main(){
	queue q;
	q.enque(5);
	q.enque(3);
	q.enque(1);
	while(!q.isEmpty())
		cout<<q.deque();
	return 0;
}