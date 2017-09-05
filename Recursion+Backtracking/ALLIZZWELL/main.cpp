#include <bits/stdc++.h>
using namespace std;
int r,c,l;
string s;
int flag=0;
char a[105][105];
int vis[105][105]={0};
void ini(){
    for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vis[i][j]=0;
            }
        }
        flag=0;
}
bool isSafe(int i,int j){
    if(i>=0 && i<r && j>=0 && j<c && vis[i][j]==0)
        return true;
    else return false;
}
bool findPath(int i,int j,int k){
    //cout<<"K:"<<k<<endl;
    if(k==l){
        return true;
    }
    if(a[i-1][j-1]==s[k] && isSafe(i-1,j-1)){
        //cout<<"i:"<<i-1<<" "<<"j:"<<j-1<<" "<<"k:"<<k<<" "<<a[i-1][j-1]<<" "<<s[k]<<endl;
        vis[i-1][j-1]=1;
        if(findPath(i-1,j-1,k+1))
            return true;
        else {vis[i-1][j-1]=0;

        }
    }
    if(a[i-1][j]==s[k] && isSafe(i-1,j)){
         //cout<<"i:"<<i-1<<" "<<"j:"<<j<<" "<<"k:"<<k<<" "<<a[i-1][j]<<" "<<s[k]<<endl;
        vis[i-1][j]=1;
        if(findPath(i-1,j,k+1))
            return true;
        else {vis[i-1][j]=0;

        }
    }
    if(a[i-1][j+1]==s[k] && isSafe(i-1,j+1)){
         //cout<<"i:"<<i-1<<" "<<"j:"<<j+1<<" "<<"k:"<<k<<" "<<a[i-1][j+1]<<" "<<s[k]<<endl;
        vis[i-1][j+1]=1;
        if(findPath(i-1,j+1,k+1))
            return true;
        else {vis[i-1][j+1]=0;

        }
    }
    if(a[i][j-1]==s[k] && isSafe(i,j-1)){
         //cout<<"i:"<<i<<" "<<"j:"<<j-1<<" "<<"k:"<<k<<" "<<a[i][j-1]<<" "<<s[k]<<endl;
        vis[i][j-1]=1;
        if(findPath(i,j-1,k+1))
            return true;
        else {vis[i][j-1]=0;

        }
    }
    if(a[i][j+1]==s[k] && isSafe(i,j+1)){
         //cout<<"i:"<<i<<" "<<"j:"<<j+1<<" "<<"k:"<<k<<" "<<a[i][j+1]<<" "<<s[k]<<endl;
        vis[i][j+1]=1;
        if(findPath(i,j+1,k+1))
            return true;
        else {vis[i][j+1]=0;

        }
    }
    if(a[i+1][j-1]==s[k] && isSafe(i+1,j-1)){
         //cout<<"i:"<<i+1<<" "<<"j:"<<j-1<<" "<<"k:"<<k<<" "<<a[i+1][j-1]<<" "<<s[k]<<endl;
        vis[i+1][j-1]=1;
        if(findPath(i+1,j-1,k+1))
            return true;
        else {vis[i+1][j-1]=0;

        }
    }
    if(a[i+1][j]==s[k] && isSafe(i+1,j)){
         //cout<<"i:"<<i+1<<" "<<"j:"<<j<<" "<<"k:"<<k<<" "<<a[i+1][j]<<" "<<s[k]<<endl;
        vis[i+1][j]=1;
        if(findPath(i+1,j,k+1))
            return true;
        else {vis[i+1][j]=0;

        }
    }
    if(a[i+1][j+1]==s[k] && isSafe(i+1,j+1)){
         //cout<<"i:"<<i+1<<" "<<"j:"<<j+1<<" "<<"k:"<<k<<" "<<a[i+1][j+1]<<" "<<s[k]<<endl;
        vis[i+1][j+1]=1;
        if(findPath(i+1,j+1,k+1))
            return true;
        else {vis[i+1][j+1]=0;

        }
    }
    return false;
}
int main()
{
   int t;cin>>t;
   while(t--){
        cin>>r>>c;
        ini();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
            }
        }
        s="ALLIZZWELL";
        l=s.length();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]=='A'){
                        ini();
                    vis[i][j]=1;
                    if(findPath(i,j,1)){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        if(flag == 1)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        cout<<endl;
   }
}
