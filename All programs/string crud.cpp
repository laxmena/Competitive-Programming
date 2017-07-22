#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int calculate(string s1,string s2){
	map<char,int> table;
	map<char,int>::iterator it;	

	int mismatch,i;
	mismatch = 0;

	//Add characters of string 1 to hash table
	for(i=0;i<s1.size();i++){
		it = table.find(s1[i]); 
		if(it != table.end())
			table[s1[i]] ++;
		else
			table.insert(pair<char,int>(s1[i],1));
	}


	//Compare string1 and string2
	for(i=0;i<s2.size();i++){
		it = table.find(s2[i]);
		if(it == table.end())
			mismatch++;
		else{
			if(!table[s2[i]]){
				mismatch++;
			}
			table[s2[i]]--;
		}
		if(mismatch>1)
			return 0;
	}
	return 1;
}

int main(){
	string s1,s2;

	cin>>s1;
	cin>>s2;

	if(calculate(s1,s2))
		cout<<"True";
	else
		cout<<"False";
	return 0;
}