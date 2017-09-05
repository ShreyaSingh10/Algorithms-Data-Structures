#include <iostream>

using namespace std;
//recursion approach
int f;
void rec(int a[],int used[],int n,int m,int i,int s){
    if(s%m ==0 && s!=0){
        //cout<<"this"<<endl;
        f=1;
        return;
    }
    else if(i==n)
    return;
    for(int i=0;i<n;i++){
        if(used[i]==1){
        s=s+a[i];
        used[i]=0;
        //cout<<"sum:"<<s<<" "<<"i+1:"<<i+1<<endl;
        rec(a,used,n,m,i+1,s);
        used[i]=1;
        s-=a[i];
        }
    }
}
int main()
{
    int arr[] = {1, 10,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m =5;int s=0,i=0;
    int used[n+1];
    for(int i=0;i<n;i++)
        used[i]=1;
    rec(arr,used,n,m,i,s);
    //cout<<"f:"<<f<<endl;
    if(f==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
