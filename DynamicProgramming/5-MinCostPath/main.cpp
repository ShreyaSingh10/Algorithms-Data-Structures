#include <iostream>

using namespace std;
int mini(int a,int b,int c){
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else return c;
}
int minCost(int cost[][3],int m,int n){
    int tab[m][n];
    tab[0][0]=cost[0][0];
    for(int i=1;i<=n;i++){
        tab[0][i]=tab[0][i-1]+cost[0][i];
        cout<<tab[0][i]<<endl;
    }
    for(int i=1;i<=m;i++){
        tab[i][0]=tab[i-1][0]+cost[i][0];
        cout<<tab[i][0]<<endl;
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            tab[i][j]=mini(tab[i-1][j],tab[i][j-1],tab[i-1][j-1])+cost[i][j];
             cout<<tab[i][j]<<endl;
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            cout<<tab[i][j]<<" ";
        cout<<endl;
    }
    return tab[m][n];
}

int main()
{
   int cost[][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
  cout<<minCost(cost, 2, 2)<<endl;
   return 0;
}
