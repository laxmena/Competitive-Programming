#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    vector < set<long int> > repo;
    long long int n,k,i,box,t;
    scanf("%lld %llld",&n,&k);
    for(i=0;i<k;i++){
        set<long int> temp; 
        repo.push_back(temp);
    }
    for(i=0;i<n;i++){
        scanf("%lld",&t);
        box = t%k;
        repo[box].insert(t);
    }
    
    set<long long int> :: iterator it;
    
    for(i=0;i<repo.size();i++){
        for(it = repo[i].begin(); it != repo[i].end(); it++)
            cout<<*it<<" ";
    }
    return 0;
}
