#include <iostream>

using namespace std;
int a[3]={1,2,3};
   int s=4;
   int n=3;
   int tab[4][5];
int coins(){
    cout<<endl;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=4;j++){
            if(j<a[i-1])
              tab[i][j]=tab[i-1][j];
            else tab[i][j]=tab[i-1][j]+tab[i][j-a[i-1]];
        }
    }
    for(int i=0;i<=3;i++){
        for(int j=0;j<=4;j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    return tab[3][4];
}
int main()
{
    for(int j=0;j<5;j++)
        tab[0][j]=0;
    for(int i=0;i<=3;i++)
        tab[i][0]=1;
    for(int i=0;i<=3;i++){
        for(int j=0;j<=4;j++)
            cout<<tab[i][j]<<" ";
        cout<<endl;
    }

   int ways=coins();
   cout<<ways<<endl;
}
