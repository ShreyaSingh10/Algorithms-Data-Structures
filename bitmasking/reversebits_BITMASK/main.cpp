#include <iostream>
#include <stdio.h>
using namespace std;

int revbits(int n)
{
    int bits=sizeof(n)*8,rev=0;
    for(int i=0;i<bits;i++)
    {
        if((n&(1<<i))>0)
            rev=rev|(1 << ((bits-1)-i));
    }
    return rev;
}
int main()
{
    //int n;
    cout<<revbits(2)<<endl;
    return 0;
}
