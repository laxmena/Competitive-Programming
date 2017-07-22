#include <iostream>
#include <vector>

using namespace std;

class node{
	public:
		vector<int> data;
		node(int data){
			this->data.push_back(data);
		}
};

int main(){
	vector<node> a;
	for(int i=0;i<10;i++){
		node t(i);
		a.push_back(t);
	}
	for(int i=0;i<a.size();i++){
		cout<<a[i].data[0]<<"->";
	}
	return 0;
}