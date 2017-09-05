#include <bits/stdc++.h>

using namespace std;
//we have to find the solution path ki kis path se rast mila
#define N 4
bool isSafe(int i,int j,int maze[N][N],int sol[N][N]){
    if(i>=0 && j>=0 && i<N && j<N && maze[i][j]!=0) //&& sol[i][j]==0)
        return true;
    else
        return false;
}
void printSolution(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isPath(int maze[N][N],int sol[N][N],int i,int j){
    if(i==N-1 && j==N-1){
        sol[i][j]=1;
        return true;
    }
    if(isSafe(i,j,maze,sol)==true){
        sol[i][j]=1;
        //cout<<"i:"<<i<<" "<<"j:"<<j<<endl;
        printSolution(sol);
        if(isPath(maze,sol,i+1,j))
            return true;
        if(isPath(maze,sol,i,j+1))
            return true;
        /*if(isPath(maze,sol,i+1,j)== true)
            return true;
        if(isPath(maze,sol,i,j+1)==true)
            return true;*/
            sol[i][j]=0;
            return false;
        }
    return false;
}
void solveMaze(int maze[N][N]){
    int sol[N][N]={ {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    if(isPath(maze,sol,0,0)==true){
        cout<<"MAZE!!"<<endl;
        printSolution(sol);
    }
    else {cout<<"NOT A MAZE"<<endl;
    printSolution(sol);
    }
}
int main()
{
    //0 is blockage 1 is for free movement
    int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
