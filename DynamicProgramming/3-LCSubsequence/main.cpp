#include <bits/stdc++.h>

using namespace std;
int lcs(string a,string b){
    int n=a.length();
    int m=b.length();
    int mem[m+5][n+5];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++)
            mem[i][j]=0;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(a[i-1]==a[j-1])
                mem[i][j]=1+mem[i-1][j-1];
            else mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
        }
    }
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++)
            cout<<mem[i][j]<<" ";
        cout<<endl;
    }
    return mem[m][n];
}

int main()
{
   int t;
   cin>>t;
   while(t--){
    string a,b;
    cin>>a;cin>>b;
    int l=lcs(a,b);
    cout<<l<<endl;
   }
}
