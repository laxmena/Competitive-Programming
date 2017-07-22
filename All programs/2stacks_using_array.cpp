#include <iostream>

using namespace std;

class stack{
	private:
		int array[100];
		int top1, top2;
		int base1, base2;
	public:
		stack(){
			top1 = -1;
			top2 = 49;
			base1 = 0;
			base2 = 50;
		}

		bool checkOverflow(int size){
			return size>=0 && size <= 50;
		}

		void push1(int data){
			top1 = top1 + 1;
			if(checkOverflow(top1-base1))
				array[top1] = data;
		}

		void push2(int data){
			top2 = top2 + 1;
			if(checkOverflow(top2-base2))
				array[top2] = data;
		}

		int pop1(){
			if(checkOverflow(top1-base1)){
				top1 -= 1;
				return array[top1+1];
			}
			return -1;
		}

		int pop2(){
			if(checkOverflow(top2-base2)){
				top2 -= 1;
				return array[top2+1];
			}
			return -1;
		}

		int size1(){
			return top1;
		}

		int size2(){
			return top2-base2;
		}

};

int main(){
	stack s;
	int temp;
	for(int i=0;i<20;i++){
		if(i%2 == 0) s.push1(i);
		else s.push2(i);
	}

	cout<<"Output\n";
	while((temp=s.pop1()) != -1){
		cout<<temp<<" ";
	}

	cout<<"\nStack2\n";
	while((temp=s.pop2()) != -1){
		cout<<temp<<" ";
	}
	
	return 0;
}