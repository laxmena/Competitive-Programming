#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string str;
        cin>>str;
        int ans = 0 , last = ' ' , cur = 0;
        for(int ch=0;ch<str.size();ch++){
            if(str[ch] == '=') continue;
            if(str[ch] != last){
                ans = max(ans , cur);
                cur = 1;
                last = str[ch];
            }
            else ++cur;
        }
        ans = max(ans , cur);
        cout<<ans + 1<<endl;
    }
}
