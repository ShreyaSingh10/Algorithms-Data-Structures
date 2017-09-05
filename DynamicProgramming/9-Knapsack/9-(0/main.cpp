#include <bits/stdc++.h>
using namespace std;

int recursion(int W,int val[],int wt[],int n){
    if(W==0 || n==0)
        return 0;
    if(wt[n-1] > W)
        return recursion(W,val,wt,n-1);
    else return max(val[n-1]+recursion(W-wt[n-1],val,wt,n-1),recursion(W,val,wt,n-1));
}
int dynamic(int W,int val[],int wt[],int n){
    int a[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0)
                a[i][j]=0;
            else if(wt[i-1]>j)   //we take i-1 because say i =1 indexing starts from zero so when i=1 we need tp access 0th index of array wt and val
                //hence we take i-1 for wt[i-1] and val[i-1] ,but in case of a[i-1][j-wt[i-1]] we have written i-1 bcz now we want to check for the
                //remaining elements and remaining weight like we did in recursion.
                a[i][j]=a[i-1][j];//return to previous func call in terms of recursion
            else a[i][j]=max(val[i-1]+a[i-1][j-wt[i-1]],a[i-1][j]);
        }
    }
     for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++)
          cout<<a[i][j]<<" ";
        cout<<endl;
     }
    return a[n][W];
}
int main(){
    int val[]={6,10,12};
    int wt[]={1,2,3};
    int W=5;
    int n=sizeof(val)/sizeof(val[0]);
    cout<<recursion(W,val,wt,n)<<endl;
     cout<<dynamic(W,val,wt,n)<<endl;
}
