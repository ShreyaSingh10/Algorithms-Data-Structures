#include <iostream>

using namespace std;
#define ll long long int
ll func(ll n,ll a[],ll s)
{
   ll t[n+1][s+1];
        for(ll i=0;i<=s;i++)
        {
            t[0][i]=0;
        }
        for(ll i=0;i<=n;i++)
        {
            t[i][0]=1;
        }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=s;j++)
            {
                if(a[i]>j)
                    t[i][j]=t[i-1][j];
                else if(a[i]<=j)
                    t[i][j]=t[i-1][j-a[i]];
            }
        }
        /*for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=s;j++)
            {
                cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return t[n][s];
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,a[105],su=0,x;cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            su=su+a[i];
        }
        if((su%2)==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
        x=func(n,a,su/2);

        if(x==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        }

    }
    return 0;
}
