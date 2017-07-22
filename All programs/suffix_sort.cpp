#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void merge(char s[], int l, int mid, int r){
	int i = l, j= mid+1, k=l;
	char temp[26];
	while(i<=mid && j<=r){
		if(s[i]>s[j])
			temp[k++] = s[j++];
		else
			temp[k++] = s[i++];
	}
	while(i <= mid)
		temp[k++] = s[i++];
	while(j <= r)
		temp[k++] = s[j++];
	for(i=l;i<=r;i++) s[i] = temp[i];
}

void mergesort(char s[], int l, int r){
	if(l<r){
		int mid = (l+r)>>1;
		mergesort(s, l, mid);
		mergesort(s, mid+1, r);
		merge(s,l,mid,r);
	}
}

int main(){
	int n;
	char s[26];
	scanf("%s %d",s,&n);
	mergesort(s, 0, strlen(s)-1);
	printf("%c",s[n-1]);
	return 0;
}