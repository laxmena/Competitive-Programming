#include <iostream>
#include <string>

using namespace std;

int main(){
	int a,b,c,i,j,t,len,ans;
	string str;
	cin>>t;
	while(t-->0){
		a=0;b=0;c=0;
		cin>>str;
		len=str.size();
		for(i=0;i<len;i++){
			switch(str[i]){
				case 'a': a++; break;
				case 'b': b++; break;
				case 'c': c++; break;
			}
		}
		if((a==0 && b==0) || (b==0 && c==0) || (c==0 && a==0))
			ans=len;
		else if((a%2==0 && b%2==0 && c%2==0) || (a%2!=0 && b%2!=0 && c%2!=0))
			ans=2;
		else
			ans=1;
		cout<<ans<<endl;
	}
	return 0;
}