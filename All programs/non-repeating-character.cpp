#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	//code
	queue<char> q;
	int t,n;
	char temp;
	cin>>t;
	while(t-->0){
	    cin>>n;
		vector<int> hash(26,0);
	    for(int i=0;i<n;i++){
	        cin>>temp;
	        hash[temp-'a']++;
	        q.push(temp);
	        while(!q.empty()){
	        	if(hash[q.front()-'a'] > 1)
	        		q.pop();
	        	else{
	        		cout<<q.front()<<" ";
	        		break;
	        	}
	        }
	        if(q.size() == 0)
	        	cout<<"-1 ";
	    }
	    cout<<"\n";
	    while(!q.empty()) q.pop();
	}
	return 0;
}