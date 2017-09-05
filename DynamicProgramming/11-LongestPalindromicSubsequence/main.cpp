#include <bits/stdc++.h>
using namespace std;
int rec(string a,int l,int i,int j){
    if(l==0)//if length 0 ans =0;not needed here can check in main only
        return 0;
    else if(i==j)//only one element
        return 1;
    else if(a[i]==a[j] && l==2)//or i+1 =j
        return 2;
    else if(a[i]==a[j])
        return rec(a,l,i+1,j-1) +2;
    else return max(rec(a,l,i+1,j),rec(a,l,i,j-1));
}
int dp(string a,int l){
    int dp[l][l];
    for(int i=0;i<l;i++){//for one element every one element in a palindrome
        dp[i][i]=1;
    }

    //for 2 and more elements
    for(int k=2;k<=l;k++){
        for(int i=0;i<l-k+1;i++){
            int j=i+k-1;
            if(a[i]==a[j] && k==2 ){
                dp[i][j]=2;
            }
            else if(a[i]==a[j])
                dp[i][j]=dp[i+1][j-1]+2;
            else dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
            }
        }
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[0][l-1];
}
int main()
{
    string a;
    cin>>a;
    int l =a.length();
    int i=0,j=l-1;
    cout<<"rec:"<<rec(a,l,i,j)<<endl;
    cout<<"dp:"<<dp(a,l)<<endl;
}
