#include <iostream>

using namespace std;
int counts(int n)
{
    int c=0;
    while(n>0)
    {
        c+=n & 1;
        n>>=1;
    }
    return c;
}
int briankernighans(int n)
{
    int c=0;
    while(n>0)
    {
        n &=n-1;
        c++;
    }
    return c;
}
//also works for setting off the rightmost bit

int main()
{
    int n;
    cout<<"enter no"<<endl;
    cin>>n;
cout<<"no of setbits"<<counts(n);
}
