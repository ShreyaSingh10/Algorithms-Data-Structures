#include <iostream>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	int a[1005];
	int mem[1005];
	while(t--){
	    int n;int maxi=1;
	    cin>>n;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        mem[i]=1;
	    }
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if(a[j]>a[i]){
	                if(mem[i]+1 >mem[j]){
	                    mem[j]=mem[i]+1;
	                    if(maxi<mem[j]){
	                        maxi=mem[j];
	                }
	            }
	        }
	   }
	  // for(int i=0;i<n;i++){
	      //printf("%d ",mem[i]);
   }
	  cout<<maxi<<endl;
}
}
