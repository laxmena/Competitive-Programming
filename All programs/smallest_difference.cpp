#include <iostream>
#include <vector>
#include <algorithm>

#define PB push_back

using namespace std;

int main(){
	vector<int> v1, v2;

	v1.PB(1);
	v1.PB(3);
	v1.PB(15);
	v1.PB(11);
	v1.PB(2);

	v2.PB(23);
	v2.PB(127);
	v2.PB(235);
	v2.PB(19);
	v2.PB(8);

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	int min = 999999;
	int elem1,elem2;
	int i,j,lenv1, lenv2, temp;
	i = 0;
	j = 0;
	
	lenv1 = v1.size();
	lenv2 = v2.size();

	while(i<lenv1 && j<lenv2){
		temp = v1[i] - v2[j];
		if(temp>0 && temp<min){
			elem1 = v1[i];
			elem2 = v2[j];
			min = temp;
		}
		if(v2[j]>v1[i])
			i++;
		else
			j++;
	}

	cout<<min;
	cout<<endl<<elem1<<" "<<elem2<<endl;
	return 0;
}