#include <bits/stdc++.h>

using namespace std;
//O(n) ---we have to see ki maximum size ka kaunsa subarray bnega jiska
//sum mximum ho...like if we have 4,-1,-5,1,7 max is 8 size 2
//if we take 6,-1,-5,1,7 max is 8 size is 5
//so we include a sum only if its not negative we a sequnece gives negative
//sum its not of our use as it will only make our sum less ...but
//if a previous sequence gives a sum 0,we can consider it as it wont,
//affect the final sum but it will add to the length of max subarray
//if we have to find min subarray with max sum wht we do is the
//moment we get a value summing to zero we put the strting \
index at next position
int dp(int a[],int n){
    int maxi=INT_MIN;
    int s=0;
    int dpa[n+1];
    for(int i=0;i<n;i++){
        s+=a[i];
        if(s<0){
            dpa[i]=0;
            s=0;
        }
        else{ dpa[i]=s;
        if(dpa[i]>maxi)
            maxi=dpa[i];
        }
    }
    return maxi;

}
int main()
{
    int a[]= {-2, -3, 4, -1, -2, 1, 5, -3};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<dp(a,n);
}
