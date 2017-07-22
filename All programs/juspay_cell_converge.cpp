#include<iostream>
#include<cstdio>

using namespace syd;

int main(){
	int n,head1,head2;
	int tail1,tail2,len1=0,len2=0;
	cin>>n;
	vector<int> adjList(n);
	for(i=0;i<n;i++){
		cin>>t;
		adjList[i] = n;
	}
	
	cin>>head1>>head2;
	tail1 = head1;
	while(tail1 != head && tail!=-1){
		tail = adjList[tail];
		len1++;
	}
	
	return 0;	
}