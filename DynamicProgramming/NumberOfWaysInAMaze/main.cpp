#include <bits/stdc++.h>

using namespace std;
//can also be solved using dfs
#define r 4
#define c 4
int cu;
void rec(int a[][4],int i,int j){
    if(i>=r || j>=c || a[i][j]==-1)
        return;
    else if(i==r-1 || j==c-1){
        cu++;
        return;
    }
    rec(a,i+1,j);
    rec(a,i,j+1);
}
//at any point if that point is not blocked calculate the sum of paths
//from top and sum of paths from left if they are not vlocked
int dp(int a[][c]){
    if(a[0][0]==-1 || a[3][3]==-1)
        return 0;
    for(int i=0;i<r;i++){//row
        if(a[i][0]==0)
            a[i][0]=1;
        else break;
    }
    for(int j=1;j<c;j++){//column
        if(a[0][j]==0)
            a[0][j]=1;
        else break;
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(a[i][j]==-1)
                continue;
            if(a[i-1][j]!=-1)
                a[i][j]+=a[i-1][j];
            if(a[i][j-1]!=-1)
                a[i][j]+=a[i][j-1];
        }
    }
    return a[r-1][c-1];
}
int main()
{
    int maze[r][c]={{0,0,0,0},{0,-1,0,0},{-1,0,0,0},{0,0,0,0}};
    cu=0;int i=0,j=0;
    rec(maze,i,j);
    cout<<cu<<endl;
    cout<<dp(maze)<<endl;
}
