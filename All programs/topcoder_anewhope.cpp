#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class ANewHope{
	public:
    	int count(vector<int> first, vector<int> second, int D){
        	int n = first.size();
            int count = 0;
            for(int i=0;i<n;i++){
            	for(int j=i+1;j<i+D;j++){
                    int index = j%n;
                	if(first[i] == second[index]){
                        count++;
                        break;
                    }
                }
            }
            return count;
        }
};

int main(){
	vector<int> first;
	vector<int> last;
	for(int i=1;i<5;i++){
		first.push_back(i);
		last.push_back(5-i);
	}
	ANewHope obj;
	cout << obj.count(first,last,3);
}