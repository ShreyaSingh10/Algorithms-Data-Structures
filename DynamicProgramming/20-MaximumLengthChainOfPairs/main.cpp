#include <bits/stdc++.h>

using namespace std;
//length of max size chain such that the second element of pair should be smaller than the
//first element of the next pair-variation of LIS
int dp(vector< pair <int,int> >v,int n){
    int dpa[n+1],maxi=INT_MIN;
    for(int i=0;i<n;i++)
        dpa[i]=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[j].first>v[i].second){
                dpa[j]=max(dpa[j],dpa[i]+1);
                if(dpa[j]>maxi)
                    maxi=dpa[j];
            }
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    vector< pair <int,int> >v;
    int x,y;
    for(int i=0;i<n;i++){
    cin>>x;cin>>y;
    v.push_back(make_pair(x,y));
   }
   sort(v.begin(),v.end());
   cout<<dp(v,n);
}
