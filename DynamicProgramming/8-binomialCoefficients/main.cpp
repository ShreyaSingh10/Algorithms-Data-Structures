#include <bits/stdc++.h>
using namespace std;
//C(n,k)=C(n-1,k-1)+C(n-1,k)
int recursion(int n,int k){
    if(k==0 || k==n){
        return 1;
    }
   // int r=recursion(n-1,k-1)+recursion(n-1,k);
    //return r;
    //write the above two lines or just the line below
    return recursion(n-1,k-1)+recursion(n-1,k);

}
int dynamic(int n,int k){
    //making a 2D array in bottom up manner
    int c[n+1][k+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){ //we take minimum bcz we dont want k i.e j to be greater than i ie n ever;
            if(j==i ||j==0)
            c[i][j]=1; //if k==0 or k==n we put 1
            else
            c[i][j]=c[i-1][j-1]+c[i-1][j]; //else we put the sum of previous two
        }
    }
    return c[n][k];
}
int main()
{
    int n,k;
    cin>>n>>k;
    int resrec=recursion(n,k);
    int resdp=dynamic(n,k);
    cout<<resrec<<" "<<resdp<<endl;
}
