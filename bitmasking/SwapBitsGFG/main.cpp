#include <iostream>
#include <stdio.h>
using namespace std;
int swap1(int x,int p1,int p2,int n)
{
int temp,a,b;
while(n--)
{
if((x&(1<<p1))!=0)
        a=1;
       else
        a=0;
       if((x&(1<<p2))!=0)
        b=1;
       else
        b=0;
       // printf("%d %d\n",a,b);
        if(a!=b)
        {
            x^=(1<<p1);
            x^=(1<<p2);
           // printf("%d",x);
           p1++;p2++;
        }
        else if(a==b)
        {
             p1++;p2++;
        }
}
return x;
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int x,p1,p2,n;
       scanf("%d %d %d %d",&x,&p1,&p2,&n);
       int sw=swap1(x,p1,p2,n);
       printf("%d\n",sw);
   }
   return 0;
}
