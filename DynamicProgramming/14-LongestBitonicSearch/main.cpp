//we do it like we make one Longest inc subsequence and one longest
//decreasing subsequence we do LIS[i]+LDS[i]-1>=maxi
//n print out the max value

#include <bits/stdc++.h>
using namespace std;
int dp(int a[],int n){
    int dpi[n+1],dpd[n+1],maxi=1,maxd=1,pos=0;
    for(int i=0;i<n;i++){
        dpi[i]=1;dpd[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i])
                dpi[j]=max(dpi[i]+1,dpi[j]);
                if(dpi[j]>maxi)
                    maxi=dpi[j];
                    pos=j+1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i])
                dpi[j]=max(dpi[i]+1,dpi[j]);
                if(dpi[j]>maxd)
                    maxd=dpi[j];
        }
    }
    cout<<maxi<<" "<<maxd<<endl;
    return max(n-pos+maxi,maxd);
}

int main() {
	//
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int a[105];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cout<<dp(a,n)<<endl;
	}
	return 0;
}
