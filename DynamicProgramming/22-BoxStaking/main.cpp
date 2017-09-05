#include <bits/stdc++.h>

using namespace std;
int dp(vector< pair< pair<int,int>,int> > v,int n){
    int dpa[3*n+1],maxi=INT_MIN;
    for(int i=0;i<3*n;i++)
        dpa[i]=v[i].second;
    for(int i=0;i<3*n;i++){
        for(int j=i+1;j<3*n;j++){
            if(v[i].first.first >v[j].first.first && v[i].first.second >
               v[j].first.second){
                dpa[j]=max(dpa[j],dpa[i]+v[j].second);
                if(dpa[j]>maxi)
                    maxi=dpa[j];
            }
        }
    }
    return maxi;
}
int main()
{
    vector< pair< pair<int,int>,int> > v;
    int n;cin>>n;
    int x,y,z;
    for(int i=0;i<n;i++){
        cin>>x>>y>>z;
        v.push_back(make_pair(make_pair(max(x,y),min(x,y)),z));
        v.push_back(make_pair(make_pair(max(x,z),min(x,z)),y));
        v.push_back(make_pair(make_pair(max(z,y),min(z,y)),x));
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<3*n;i++)
        cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
    cout<<"dp:"<<dp(v,n)<<endl;
}
