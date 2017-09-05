#include <bits/stdc++.h>

using namespace std;
int a[20],n,bitree[20]={0};
void bitConstruction()
{
    for(int j=0;j<n;j++)
    {
        int i=j+1;
        while(i<=n)
        {
        bitree[i]+=a[j];
        i+=i&(-i);
        }
    }
}
int bitSum(int d)
{
    int sum=0;
    while(d>0)
    {
        sum=sum+bitree[d];
        d-=d&(-d);
        //printf("%d",d);
    }
    //printf("\n");
    return sum;
}
void bitUpdate(int d,int b)
{
        int z=b;
        b=b-a[d-1];
        a[d-1]=z;
        while(d<=n)
        {
        bitree[d]+=b;
        d+=d&(-d);
        }
        for(int j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int q,o,d,b;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        bitConstruction();

        while(q--)
        {
            int sum1=0,sum2=0,sumf=0;
            scanf("%d %d %d",&o,&d,&b);
            if(o==1)
            {
                sum1=bitsum(b);
                sum2=bitsum(d-1);
                sumf=sum1-sum2;
                printf("%d\n",sumf);
            }
            if(o==2)
                bitupdate(d,b);

        }
    }
    return 0;
}
