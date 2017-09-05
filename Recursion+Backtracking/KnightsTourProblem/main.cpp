#include <bits/stdc++.h>

using namespace std;
#define N 8
bool issafe(int maze[N][N],int i,int j){
    if(i>=0 && j>=0 && i<N && j<N && maze[i][j]==-1)
        return true;
    else return false;
}
void printMaze(int maze[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<maze[i][j]<<" ";
        cout<<endl;
    }
}
bool knightsPath(int maze[N][N],int i,int j,int c){
    //cout<<"c:"<<c<<endl;
    if(c==N*N)
        return true;

    if(issafe(maze,i+2,j+1)){
         maze[i+2][j+1]=c;
        if(knightsPath(maze,i+2,j+1,c+1))
            return true;
        else maze[i+2][j+1]=-1;
    }

    if(issafe(maze,i+1,j+2)){
             maze[i+1][j+2]=c;
        if(knightsPath(maze,i+1,j+2,c+1))
            return true;
        else maze[i+1][j+2]=-1;
    }

    if(issafe(maze,i-1,j+2)){
             maze[i-1][j+2]=c;
        if(knightsPath(maze,i-1,j+2,c+1))
            return true;
        else maze[i-1][j+2]=-1;
    }

    if(issafe(maze,i-2,j+1)){
             maze[i-2][j+1]=c;
        if(knightsPath(maze,i-2,j+1,c+1))
            return true;
        else maze[i-2][j+1]=-1;
    }
    if(issafe(maze,i-2,j-1)){
             maze[i-2][j-1]=c;
        if(knightsPath(maze,i-2,j-1,c+1))
            return true;
        else maze[i-2][j-1]=-1;
    }

    if(issafe(maze,i-1,j-2)){
             maze[i-1][j-2]=c;
        if(knightsPath(maze,i-1,j-2,c+1))
            return true;
        else maze[i-1][j-2]=-1;
    }

    if(issafe(maze,i+1,j-2)){
             maze[i+1][j-2]=c;
        if(knightsPath(maze,i+1,j-2,c+1))
            return true;
        else maze[i+1][j-2]=-1;
    }

    if(issafe(maze,i+2,j-1)){
             maze[i+2][j-1]=c;
        if(knightsPath(maze,i+2,j-1,c+1))
            return true;
        else maze[i+2][j-1]=-1;
    }

    return false;
}
int main(){
    int maze[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            maze[i][j]=-1;
    }
        maze[0][0]=0;
        if(knightsPath(maze,0,0,1))
            printMaze(maze);
        else
            cout<<"OOOOPPS"<<endl;
}
