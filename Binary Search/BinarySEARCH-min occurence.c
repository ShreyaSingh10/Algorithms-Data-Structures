#include <bits/stdc++.h>
using namespace std;
int a[15];
int binarySearch(int l,int u,int x){
	int o=INT_MAX;
	while(l<=u){
		int mid = l+(u-l)/2;
		//cout<<"midd:"<<mid<<endl;
		if(a[mid]==x){
			cout<<"mid:"<<mid<<endl;
			if(mid<o){
				o=mid;
			}
		            u=mid-1;
		}
		else if(a[mid]<x){
			l=mid+1;
		}
		else if(a[mid]>x){
			u=mid-1;
		}

	}
	cout<<"occurence:"<<o<<endl;
}
int main() {
	// your code goes here
           	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x;
	cin>>x;
	binarySearch(0,n-1,x);
}
