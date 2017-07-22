#include<bits/stdc++.h>

using namespace std;

int mod;
void merge(int arr[], int l, int mid, int r){
	int temp[10001];
	int i=l, j=mid+1, k=l;
	while(i<=mid && j<=r){
		if(arr[i]%mod <= arr[j]%mod)
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=mid) temp[k++] = arr[i++];
	while(j<=r) temp[k++] = arr[j++];
	for(i=l;i<=r;i++)
		arr[i] = temp[i];
}

void mergesort(int arr[], int l, int r){
	if(l<r){
		int mid = (l+r)>>1;
		mergesort(arr, l, mid);
		mergesort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

int main(){
	int a[10001];
	int i,n,t;
	scanf("%d%d",&n,&mod);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	for(i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}