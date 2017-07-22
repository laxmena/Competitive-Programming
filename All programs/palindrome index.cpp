#include <iostream>
#include <string>

using namespace std;

int checkPalindrome(string s){
	int i = 0, j = s.length() - 1;
	while (i < j){
		if (s[i] != s[j]) 
			return -1;
		i++;
		j--;
	}
	return 1;
}

int main(){
	int t;
	cin >> t;
	while (t-->0){
		string str;
		cin >> str;
		int i = 0, len = str.length(), j = len - 1;
		int ans = -1;
		while (i < j && str[i] == str[j]){
			i+=1;
			j-=1;
		}
		if (i < j){
			string str1 = str.substr(0, i) + str.substr(i + 1, str.length() - i - 1);
			if(checkPalindrome(str1))
				ans = i;
			string str2 = str.substr(0, j) + str.substr(j + 1, str.length() - j - 1);
			if(checkPalindrome(str2)) 
				ans = j;
		}
		cout << ans << endl;
	}
	return 0;
}