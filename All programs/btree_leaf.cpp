#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

int main()
{
    int t,n;
    long long int temp1,temp2;
    list <long long int> val;
    list <long long int> tempQ;
    list <long long int> :: iterator it;
    scanf("%d",&t);
    tempQ.empty();
    while(t-->0){
        scanf("%d",&n);
        while(n-->0){
        	scanf("%lld",&temp1);
        	val.push_back(temp1);
        }
        while(val.size() > 1){
        	n = val.size()-1;
        	cout << n;
        	while(n>0){
        		it = val.begin();
        		cout << *it << endl;
        		temp1 = *it;
        		val.pop_front();
        		it = val.begin();
        		temp2 = *it;
        		temp1 = temp1 ^ temp2;
        		val.pop_front();
        		tempQ.push_back(temp1);
        		cout<<"\nn: "<<n<<endl;
        		n = n-2;
        	}
        	if(n==0){
        		it = val.begin();
        		temp1 = *it;
        		tempQ.push_back(temp1);
        	}
        	cout<<"val: "<<val.size()<<endl;
        	cout<<"tempQ: "<<tempQ.size()<<endl;
        	val.empty();
        	val = tempQ;
        	tempQ.empty();
        }

    }
    return 0;
}
