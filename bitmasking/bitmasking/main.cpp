#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[104],n,s=0,s1=0,c=0;
        //printf("enter ur number\n");
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s=s+a[i];
            //printf("s = %d\n",s);
        }
        //printf("s = %d\n",s);
        if(s%2==1)
        {
            printf("NO\n");
            return 0;
        }
        else if(s%2==0)
        {
            for(int i=0;i<(1<<n);i++)
            {
                for(int j=0;j<n;j++)
                {
                    if((i&(1<<j))!=0)
                    {
                        s1=s1+a[j];
                        //qprintf("%c",a[n-1-j]);
                    }
                }
                if(s1==(s/2))
                {
                    c=1;
                    break;
                }
                else
                //printf("%d\n",s1);
                s1=0;

                //printf("\n");
            }
        }
        if(c>0)
        printf("YES\n");
        else
        printf("NO\n");

    }
    return 0;
}
