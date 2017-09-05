#include <bits/stdc++.h>

using namespace std;
int vis[64][64]={0};
int mini=INT_MAX;
void ini(int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;
        }
    }
    mini=INT_MAX;
}
bool isSafe(int i,int j,int m,int n){
    if(i>=0 && i<m && j>=0 && j<n )
        return true;
        else
            return false;
}
void minHops(int matrix[64][64],int i,int j,int m,int n,int c){

    if(isSafe(i+matrix[i][j],j,m,n)){
        if(vis[i+matrix[i][j]][j]==0 || (vis[i+matrix[i][j]][j]!=0 && c<vis[i+matrix[i][j]][j]))
            vis[i+matrix[i][j]][j]=c;
        minHops(matrix,i+matrix[i][j],j,m,n,c+1);
    }
    if(isSafe(i,j+matrix[i][j],m,n)){
        if(vis[i][j+matrix[i][j]]==0 || ( vis[i][j+matrix[i][j]]!=0 && c<vis[i][j+matrix[i][j]]))
            vis[i][j+matrix[i][j]]=c;

        minHops(matrix,i,j+matrix[i][j],m,n,c+1);
    }

    return;
}

int main()
{
    int matrix[64][64];
    int m,n;
    cin>>m>>n;
    ini(m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    vis[0][0]=1;
    minHops(matrix,0,0,m,n,2);
    cout<<vis[m-1][n-1]<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
}
