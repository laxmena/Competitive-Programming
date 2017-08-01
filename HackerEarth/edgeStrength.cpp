#include <bits/stdc++.h>

using namespace std;

int calculateSubTreeNodes(int node, vector<int> subTreeNodes, vector<vector<int> > tree){
	cout<<"Aaa";
    if(tree[node].size() == 0){return 1;}
    int s = tree[node].size();
    subTreeNodes[node] = calculateSubTreeNodes(tree[node][0], subTreeNodes, tree);
    if(s==2) subTreeNodes[node] += calculateSubTreeNodes(tree[node][1], subTreeNodes, tree);
    return subTreeNodes[node];
}

int main(){
	int i,n,temp1,temp2,subNodes;
	cin>>n;
	vector<vector<int> > tree(n+1);
	vector<int> subTreeNodes(n,1);

	cin>>temp1>>temp1;

	vector<int> from(n);
	vector<int> to(n);

	for(i=0;i<n-1;i++){
		cout<<"abc\n";
		cin>>temp1>>temp2;
		from[i] = temp1;
		to[i] = temp2;
		cout<<"t1,t2: "<<temp1<<" "<<temp2<<endl;
		tree[temp1].push_back(temp2);
		cout<<"bla\n";
	}

	for(i=0;i<=n;i++){
		cout<<i<<": "<<endl;
		for(int j=0;j<tree[i].size();j++)
			cout<<tree[i][j]<<" ";
		cout<<endl;
	}

	calculateSubTreeNodes(1, subTreeNodes, tree);

	cout<<"solution: \n";
	for(i=0;i<n-1;i++){
		cout<<from[i] <<" "<<to[i]<<"=> subNodes: ";
		subNodes = subTreeNodes[to[i]];
		cout<<subNodes<<" "<<subNodes*(n-subNodes)<<endl;
	}
	return 0;
}