/*
 *  Author: Lakshmanan Meiyappan
 *  Handle: Codechef    : lax2804
 *          HackerRank  : lax2804
 *          HackerEarth : @lakshmanan.meiyappan
 *          SPOJ        : laxmena
 *
 *          GitHub      : https://github.com/laxmena            
 *  
 *          Website     : https://laxmena.github.io/website/
 *
 *          Email       : lakshmanan.meiyappan@gmail.com
 *          Attribution : https://github.com/laxmena/Competitive-Programming/blob/master/Template/Template2.cpp
 *  
 */


#include <bits/stdc++.h>

using namespace std;

#define SI(t)   scanf("%d",&t)
#define SL(t)   scanf("%ld",&t)
#define SLL(t)  scanf("%lld",&t)
#define SC(t)   scanf("%c",&t)
#define SS(t)   cin>>t
#define SF(t)   scanf("%f",&t)
#define SLF(t)  scanf("%lf",&t)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(container) container.begin(), container.end()
#define rall(container) container.end(), container.begin()
#define RFOR(i, from, till, dec) for(i=from; i>=till; i-=dec)
#define FOR(i, from, till, inc) for(i=(from); i<(till); i+=(inc))
#define FOREACH(it, container) for(it=container.begin(); it != container.end(); it++)

#define MP      make_pair
#define PB      push_back
#define MAX     (int)1e9
#define EPS     1e-9
#define PI      3.1415926535897932384626433832795
#define MOD     1000000007

const double pi=acos(-1.0);
typedef vector<int> VI;
typedef vector<float> VF;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<long> VL;
typedef list<int> LI;
typedef list<string> LS;
typedef set<int> SETI;
typedef set<char> SETC;
typedef set<float> SETF;
typedef set<long> SETL;
typedef set<long long> SETLL;
typedef stack<int> STACKI;
typedef stack<char> STACKC;
typedef stack<float> STACKF;
typedef queue<int> QI;
typedef queue<char> QC;
typedef queue<float> QF;
typedef map<int,int> MAPII;
typedef map<int,char> MAPIC;
typedef map<char,int> MAPCI;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;
 
VI freq(26,0);

int checkPalindrome(string str){
    int l = str.length();

    for (int i = 0; i < l; i++)
        freq[str[i]-'A']++;

    int oddOccurance = 0;

    for (int i = 0; i < 26; i++)
        if (freq[i] % 2 == 1)
            oddOccurance++;

    if ((l % 2 == 1 && oddOccurance == 1 ) || (l %2 == 0 && oddOccurance == 0))
        return 1;
    else
        return 0;
}
 
string reverse(string str){
    string rstr = str;
    reverse(rstr.begin(), rstr.end());
    return rstr;
}
 
void printAllPossiblePalindromes(string str){
    if (!checkPalindrome(str)) return;
    int l = str.length();
    string half = "",palin;
    char oddChar;
    for (int i = 0; i < 26; i++){
        if(freq[i] % 2 == 1)
            oddChar = i + 'A';
        half += string(freq[i] / 2, i + 'A');
    }
     do{
        palin = half;
        if (l % 2 == 1)
            palin += oddChar;
        palin += reverse(half);
        cout << palin << endl;
    }
    while (next_permutation(half.begin(), half.end()));
}
 
int main()
{
    string s;
    cin>>s;
    printAllPossiblePalindromes(s);
    return 0;
}