#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int number_needed(string a, string b) {
   vector<int> str1(26,0);
   int i,count=0;
   for(i=0;i<a.size();i++){
       (str1[a[i]-'a'])++;
   }
   for(i=0;i<b.size();i++){
       str1[b[i]-'a'] = str1[b[i]-'a'] - 1;
   }
   for(i=0;i<26;i++)
      count += abs(str1[i]);
  return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}

