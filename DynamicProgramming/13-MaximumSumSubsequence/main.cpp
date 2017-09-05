#include <bits/stdc++.h>
using namespace std;
//find the maxi sum such that the max sum shud be formed by
//elements which are subsequently increasing
int maxi=INT_MIN;
int maxSumIS(int a[],int n){
    int dp[n+1];
    for(int i=0;i<n;i++){
        dp[i]=a[i];
        if(maxi<dp[i])
            maxi=dp[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                dp[j]=dp[i]+a[j]>dp[j]?dp[i]+a[j]:dp[j];
                if(maxi<dp[j])
                    maxi=dp[j];
             }
         }
    }
    return maxi;
}
int main()
{
  int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumIS( arr, n );
    return 0;
}
