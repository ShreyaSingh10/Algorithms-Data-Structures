#include <iostream>

using namespace std;
int rec(string a,string b,int n,int m){
    //base condition
    if(n==0 || m==0)
        return 0;
    if(a[n-1]==b[m-1])
        return 1+rec(a,b,n-1,m-1);
    else
    return max(rec(a,b,n-1,m),rec(a,b,n,m-1));
}
int dp(string a,string b,int n,int m){
    int dpa[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                dpa[i][j]=0;
            else if(a[i-1]==b[j-1])
                dpa[i][j]=1+dpa[i-1][j-1];
            else dpa[i][j]=max(dpa[i-1][j],dpa[i][j-1]);
        }
    }
    return dpa[n][m];
}
int main()
{
    string a="abcdxyz";
    string b="xyzabcd";
    int n=a.length();
    int m=b.length();
    cout<<"rec:"<<rec(a,b,n,m)<<endl;
    cout<<"dp:"<<dp(a,b,n,m)<<endl;
}
