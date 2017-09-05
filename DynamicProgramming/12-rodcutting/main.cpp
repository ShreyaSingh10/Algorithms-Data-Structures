#include <bits/stdc++.h>

using namespace std;
int maxi=INT_MIN;
int rec(int a[],int i,int n){
    if(n<=0 || i>n)
        return 0;
    return max(a[i-1]+rec(a,i,n-i),rec(a,i+1,n));

}
int dp(int a[], int n)
{
   int dp[n+1][n+1];
   for(int i=0;i<=n;i++){
       for(int j=0;j<=n;j++){
        if(i==0 || j==0)
            dp[i][j]=0;
        else if(j<i)
            dp[i][j]=dp[i-1][j];
        else dp[i][j]=max(a[i-1]+dp[i][j-i],dp[i-1][j]);
       }
   }
   return dp[n][n];
}
//dp explaination-if we have no pieces and we want to make a sum ...its not possible so it will be 0
//if we have no length to be cut and we have values of pieces the max sum will again be 0;
//now if the size of piece is greater than the length req we check for the previous size smaller than that present size
//else wht we do is suppose we have to make length 3 and we are currently checking for size 2 so we take size 2 add the price now we are
//left wid length 1 now we can check ki 2 lengths se one bna toh kya value tha and add that to the price off 2
//then check ki 2 lie bina sirf 1 se max value kya bna n compare both of thm

int main()
{
    int arr[] = {1,5,8,9,10,17,17,20};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<rec(arr,1,n)<<endl;
    //cout<<cutRod(arr,n)<<endl;
    cout<<dp(arr,n)<<endl;
}
