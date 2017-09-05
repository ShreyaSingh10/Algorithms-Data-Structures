#include <bits/stdc++.h>

using namespace std;
//no of ways to reach a score in a game\
obviously it can be done in on2 using dp like the coin change when\
unlimited number of each coin was present ,now in this qstn since
//player can score only 3 ,5,10 points we need only one one D array\
//and update in it itself
int dp(int n){
    int dpa[n+1];
    memset(dpa,0,sizeof(dpa));
    dpa[0]=1;//if sum is 0 no of ways =1 by not including any
    for(int i=3;i<=n;i++)
        dpa[i]+=dpa[i-3];
    for(int i=5;i<=n;i++)
        dpa[i]+=dpa[i-5];
    for(int i=10;i<=n;i++)
        dpa[i]+=dpa[i-10];
    return dpa[n];
}
int main()
{
  int n;cin>>n;
  cout<<"dp:"<<dp(n)<<endl;
}
