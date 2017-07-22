#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int stringReduction(string a) {
   int ca=0,cb=0,cc=0;
   for(int i=0;i<a.size();i++){
       switch(a[i]){
           case 'a': ca++; break;
           case 'b': cb++; break;
           case 'c': cc++; break;
       }   
   } 
   if((ca == 0 && (cb == 0 || cc == 0)) || (cb==0 && cc==0))
       return a.size();
   int temp = ca%2 + cb%2 + cc%2;
   if(temp==0 || temp==3)
       return 2;
   return 1;
}

int main() {
    int res, t, i;
    cin>>t;
    string a;
    for (i=0;i<t;i++) {
        cin>>a;
        res=stringReduction(a);
        cout<<res<<endl;  
    }
    return 0;
}

