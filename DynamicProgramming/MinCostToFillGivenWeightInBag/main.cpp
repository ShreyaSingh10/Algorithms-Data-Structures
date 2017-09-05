#include <bits/stdc++.h>

using namespace std;
int dp(int cost[],int w,int n){
    int dpa[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++)
            dpa[i][j]=-1;
    }
    for(int j=0;j<=w;j++){
        if(cost[0]!=-1)
            dpa[0][j]=cost[0]*j;
    }
    for(int i=0;i<n;i++){
        if(cost[i]!=-1)
            dpa[i][0]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            cout<<dpa[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<n;i++){
            if(cost[i]==-1)
            continue;
        for(int j=1;j<=w;j++){
            if(j<i+1)
                dpa[i][j]=dpa[i-1][j];
            else if(j>=i+1 && dpa[i][j-i-1]!=-1){
                if(dpa[i-1][j]!=-1)
                    dpa[i][j]=min(cost[i]+dpa[i][j-i-1],dpa[i-1][j]);
                else
                    dpa[i][j]=cost[i]+dpa[i][j-i-1];
            }
            else
                dpa[i][j]=dpa[i-1][j];
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<=w;j++){
            cout<<dpa[i][j]<<" ";
        }
        cout<<endl;
    }
    return dpa[n-1][w];
}
int main()
{
    int cost[]={-1, -1, 4, 5, -1};
    int w=5;
    int n=sizeof(cost)/sizeof(cost[0]);
    cout<<"dp:"<<dp(cost,w,n)<<endl;
}
