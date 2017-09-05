#include <iostream>
#include <stdio.h>
using namespace std;
int a[4][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};// This is the text editor interface.
// Anything you type or change here will be seen by the other person in real time.
int bsearch(int i,int r,int l,int n)
{
  //finding column wise
  if(r>l)
        return 0;
    int mid=r+(l-r)/2;
    if(n==a[i][mid])
        return 1;
    else if(n<a[i][mid])
        bsearch(i,r,mid-1,n);
    else if(n>a[i][mid])
        bsearch(i,mid+1,l,n);
}
int bsearch2(int r,int l,int n)
{
    //first finding row wise
    if(r>l )
        return 0;
    int mid=r+(l-r)/2;
    if(n<a[mid][0])
        bsearch2(r,mid-1,n);
    else if(n>=a[mid][0] && n<=a[mid][4])
     return mid;
    else if(n>a[mid][0])
             bsearch2(mid+1,l,n);

}


int main()
{
    int n,r=0,l=4,i=0,bs,r1=0,l1=3;
    printf("enter the number u want to find\n");
    scanf("%d",&n);
    int m=bsearch2(r1,l1,n);
    bs=bsearch(m,r,l,n);
    if(bs==1)
        printf("found\n");
    else if(bs==0)
        printf("not found\n");
    return 0;
}
