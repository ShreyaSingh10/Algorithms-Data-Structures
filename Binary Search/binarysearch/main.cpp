#include <iostream>
#include <stdio.h>
using namespace std;
int a[10]={3,5,7,8,9,12,14,18,19,21};
int bsearch(int r,int l,int n)
{
    if(r>l)
        return 0;
    int mid=(r+l)/2;
    if(n==a[mid])
        return 1;
    else if(n<a[mid])
        bsearch(r,mid-1,n);
    else if(n>a[mid])
        bsearch(mid+1,l,n);
}
int main()
{
    int n,r=0,l=9;
    printf("enter the number u want to find\n");
    scanf("%d",&n);
    int bs=bsearch(r,l,n);
    if(bs==1)
        printf("found\n");
    else
        printf("not found\n");
    return 0;
}
