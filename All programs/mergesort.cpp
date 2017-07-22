#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printer(vector<int> a){
	int i=0;
	for(i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void merge(vector<int> &f,vector<int> &s,int b,int mid,int e){
	int i,j,k;
	vector<int> lf,rf,ls,rs;
	for(i=b;i<mid;i++){
		lf.push_back(f[i]);
		ls.push_back(s[i]);
	}
	for(i=mid;i<e;i++){
		rf.push_back(f[i]);
		rs.push_back(s[i]);
	}
	i=0;j=0;k=b;
	int n1=lf.size(), n2=rf.size();
	while(i<n1 && j<n2){
		if(lf[i]<rf[j]){
			f[k]=lf[i];
			s[k]=ls[i];
			i++;
		}
		else{
			f[k]=rf[j];
			s[k]=rs[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		f[k]=lf[i];
		s[k]=ls[i];
		i++;
		k++;
	}
	while(j<n2){
		f[k]=rf[j];
		s[k]=rs[j];
		j++;
		k++;
	}	
}

void mergesort(vector<int> &f,vector<int> &s,int b,int e){
	if(e-b<2)
		return;
	int mid = (b+e)/2;
	mergesort(f,s,b,mid);
	mergesort(f,s,mid,e);
	merge(f,s,b,mid,e);
}

int activity(vector<int> f,vector<int> s,int n){
	int c=0,prev=0,i;
	for(i=0;i<n;i++){
		// cout<<"F Prev: "<<f[prev]<<" S: "<<s[i];
		if(i==0){
			prev=i;
			c++;
		}
		else if(f[prev]<=s[i]){
			// cout<<" <-- Success";
			c++;
			prev=i;
		}
		// cout<<endl;
	}
	return c;
}

using namespace std;

int main(){
	int t,n,i,temp,act_count;
	cin>>t;
	while(t-->0){
		vector <int> s,f;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>temp;
			s.push_back(temp);
		}
		for(i=0;i<n;i++){
			cin>>temp;
			f.push_back(temp);
		}
		mergesort(f,s,0,n);
		// printer(s);
		// printer(f);
		act_count = activity(f,s,n);
		cout<<act_count<<endl;
	}
	return 0;	
}