#include <bits/stdc++.h>
using namespace std;
bool rec(int a[],int i,int s,int n){
    //base
    if(s==0)
        return 1;
    else if (s!=0 && i==n)
        return 0;
    if(a[i]>s)//if a number is greater thn sum we dont include it
        return rec(a,i+1,s,n);
    return (rec(a,i+1,s-a[i],n)||rec(a,i+1,s,n));
}
int dp(int b[],int s,int n){
    int a[n+1][s+1];
    for(int j=0;j<=s;j++)
        a[0][j]=0;
    for(int i=0;i<=n;i++)
        a[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(j>b[i-1])
                a[i][j]=a[i-1][j];
            else a[i][j]=a[i-1][j]||a[i-1][j-b[i-1]];
        }
    }
    return a[n][s];
}
int main()
{
    int a[]={1,5,11,5};//if sum==odd then obviously cant be divided
    //into 2 parts
    int n=sizeof(a)/sizeof(a[0]);
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
        if(sum%2==1)
            cout<<"NO"<<endl;
        else{
        cout<<"s:"<<sum/2<<endl;
        cout<<rec(a,0,sum/2,n)<<endl;
        cout<<dp(a,sum/2,n);
        }
}
