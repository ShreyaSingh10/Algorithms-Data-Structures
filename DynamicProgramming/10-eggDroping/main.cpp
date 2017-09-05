#include <bits/stdc++.h>
using namespace std;
//min no. of trials to find the floor jisse egg nai tutega
//min attempts to find from which floor eggs will break??
int dp(int eg,int flr){
    int a[eg+1][flr+1];
    for(int j=1;j<=flr;j++){
        a[0][j]=j;
    }
    for(int i=2;i<=eg;i++){
        for(int j=1;j<=flr;j++){
            if(j<i)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=1+min(a[i-1][j-1],a[i][flr-j]);
        }
    }
}
int rec(int eg,int flr){
    if(eg==1) {
        return flr;
    }
    return 1+min(rec(eg-1,flr-1),rec(eg,flr-))
}

int main()
{
     int eg,flr;
     cin>>eg>>flr;
     cout<<dp(eg,flr)<<endl;
}
