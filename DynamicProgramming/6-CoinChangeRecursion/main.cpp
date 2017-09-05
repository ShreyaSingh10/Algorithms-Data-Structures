#include <iostream>

using namespace std;
//Given unlimited coins,what are the no. of ways to get a sum?
//RECURSION!!!
int c;
void coin(int a[],int s,int i,int n,int sum){
    if(i==n)
        return;
    if(sum==s){
            //cout<<"here"<<endl;
            c++;
            //cout<<"c:"<<c<<endl;
        return;
    }
    else if(sum>s)
        return;
    else{
        sum+=a[i];
        //cout<<"c:"<<c<<endl;
        coin(a,s,i,n,sum);
        sum-=a[i];
        coin(a,s,i+1,n,sum);
    }
}
int main()
{
    int a[4]={2,5,3,6};
    int s=10,sum=0,i=0;
    int n=4;
    coin(a,s,i,n,sum);
    cout<<c<<endl;
}
