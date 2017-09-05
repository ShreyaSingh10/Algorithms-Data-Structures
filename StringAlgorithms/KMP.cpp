#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char txt[20]="AABAACAADAABAAABAA";
char pat[10]="AABA";int lps[10];
void lpsarr(int m)
{
    int len=0,i=1;lps[0]=0;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        if(pat[i]!=pat[len])
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
        }
        if(pat[i]!=pat[len])
        {
            if(len!=0)
            len=lps[len-1];
        }
    }
}
void kmpsearch()
{
    int n=strlen(txt);
    int m=strlen(pat);
    int j=0,i=0;
    lpsarr(m);
    while(i<n){
        if(txt[i]==pat[j]){
            i++;j++;
        }
        if(j==m){
            printf("found at index:%d",i-j);
        }
        if(txt[i]!=pat[j]){
            if(j!=0)
            j=lps[j-1];
            if(j==0){
                i++;
            }
        }
    }
}
int main()
{
    kmpsearch();
    return 0;
}
