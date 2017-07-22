#include <bits/stdc++.h>

using namespace std;

priority_queue <double> max_heap_left;
priority_queue <double, vector<double>, greater<double> > min_heap_right;
	
void compute_median(double x, double &median){
	if(max_heap_left.size() > min_heap_right.size()){
		if(x < median){
			min_heap_right.push(max_heap_left.top());
			max_heap_left.pop();
			max_heap_left.push(x);
		}
		else
			min_heap_right.push(x);
		median = min_heap_right.top() + max_heap_left.top();
		median /= 2.0;
	}

	else if(max_heap_left.size() == min_heap_right.size()){
		if(x > median){
			min_heap_right.push(x);
			median = min_heap_right.top();
		}
		else{
			max_heap_left.push(x);
			median = max_heap_left.top();
		}
	}

	else{
		if(x > median){
			max_heap_left.push(min_heap_right.top());
			min_heap_right.pop();
			min_heap_right.push(x);
		}
		else
			max_heap_left.push(x);

		median = min_heap_right.top() + max_heap_left.top();
		median /= 2.0;
	}
}

int main(){
	double median = 0.0;
	double t;
	int i,n;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%lf",&t);
		compute_median(t,median);
		printf("%.1lf\n",median);
	}
	return 0;
}