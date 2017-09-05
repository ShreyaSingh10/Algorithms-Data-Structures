#include <bits/stdc++.h>

using namespace std;
int board[1005][1005];
int n,flag=0;
void printBoard(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

bool issafe(int row,int col){
    int k,l;
    for(k=0;k<col;k++){
        if(board[row][k]==1)
        return false;
    }
    for(k=row,l=col;k>=0 && l>=0;k--,l--){
        if(board[k][l]==1)
            return false;
    }
    for(k=row,l=col;k<n && l>=0;k++,l--){
        if(board[k][l]==1)
            return false;
    }
    return true;
}
bool queenpath(int j){
    if(j>=n)
        return true;
    for(int i=0;i<n;i++){
        if(issafe(i,j)){
            board[i][j]=1;
            printBoard();
            cout<<"j new:"<<j+1<<endl;
            if(queenpath(j+1))
                return true;
             board[i][j]=0;
        }
    }
    return false;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
          board[i][j]=0;
    }
    if(queenpath(0)==true){
        cout<<"YAY!"<<endl;
        printBoard();
    }
    else cout<<"Not a Board"<<endl;
}
