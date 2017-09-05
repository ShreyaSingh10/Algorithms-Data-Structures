#include <bits/stdc++.h>
using namespace std;
int mini(int a,int b,int c){
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else return c;
}
int editDistance(string a,string b){
    int m=a.length();int n=b.length();
    int tab[m+5][n+5];
    tab[0][0]=0;
    for(int i=1;i<=m;i++)
       tab[i][0]=1+tab[i-1][0];
    for(int j=1;j<=n;j++)
       tab[0][j]=1+tab[0][j-1];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                tab[i][j]=tab[i-1][j-1];
            else
                tab[i][j]=1+mini(tab[i-1][j-1],tab[i-1][j],tab[i][j-1]);
                //1.replace 2.remove 3.edit
    }
    }
    return tab[m][n];
}
int main() {
	//code
    string a="shreya";
    string b="shanaya";
    cout<<editDistance(a,b)<<endl;
	return 0;
}
