#include <bits/stdc++.h>
using namespace std;
//subset sum which sums upto S
int rec(int a[],int i,int s,int n){
    //base
    if(s==0)
        return 1;
    else if(i==n)
        return 0;
    if(a[i]>s)
    return rec(a,i+1,s,n);
    return rec(a,i+1,s-a[i],n)||rec(a,i+1,s,n);
}
int dp(int a[],int s,int n){
    int dpa[n+1][s+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++)
            dpa[i][j]=0;
    }
     dpa[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(a[i-1]>j)
                dpa[i][j]=dpa[i-1][j];
            else dpa[i][j]=dpa[i-1][j-a[i-1]]||dpa[i-1][j];
        }
    }
    return dpa[n][s];
}
int main()
{
  int a[]={3, 34, 5, 12, 5, 3};
  int n=sizeof(a)/sizeof(a[0]);
  int sum=8;
  int i=0;
  cout<<"rec:"<<rec(a,i,sum,n)<<endl;
  cout<<"dp:"<<dp(a,sum,n)<<endl;
}
