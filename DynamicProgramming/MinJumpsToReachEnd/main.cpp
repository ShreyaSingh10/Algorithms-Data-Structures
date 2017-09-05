#include <bits/stdc++.h>
using namespace std;
int dp(int a[],int n){
    int dpa[n+1];
    for(int i=0;i<n;i++)
        dpa[i]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=a[i];j++){
            if(dpa[i+j]==0)
                dpa[i+j]=dpa[i]+1;
            else dpa[i+j]=min(dpa[i]+1,dpa[i+j]);
        }
    }
    return dpa[n-1];
}
int main()
{
   int a[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};//1, 3, 6, 1, 0, 9
   int n=sizeof(a)/sizeof(a[0]);
   cout<<"dp:"<<dp(a,n)<<endl;
}
