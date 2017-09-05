#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int x,y,l,r;
        scanf("%lld %lld %lld %lld",&x,&l,&r,&y);
        l=l-1;r=r-1;
        for(long long int i=l;i<=r;i++)
        {
            if((y&(1<<i))!=0)
                {
                    x=(x|(1<<i));
                    //printf("%d\n",x);
                }
        }
        printf("%lld\n",x);
    }
    return 0;
}

