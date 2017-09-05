#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> > g[10005];
ll dist[10005];
void djikstra(ll x)
{
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;//since priority queue gives max to min we use
    //this syntax so that v get min to max.
    //in priority q d first element is alwways the element according to which we want the min value.
    ll node,i;
    pair<ll,ll> temp;//temp is the variable in which hwe will store the priority q's front element.
    pq.push(make_pair(0,x));
    dist[x]=0;//set distance of first to zero.
    while(!pq.empty())
    {
        temp=pq.top();
        pq.pop();
        node=temp.second;//second wale is the nodes number//first value is the edge distance.
        for(i=0;i<g[node].size();i++) //adjacency list representation of node will go in bfs till its size.
        {
            if(dist[g[node][i].second]>dist[node]+g[node][i].first)
            {
                dist[g[node][i].second]=g[node][i].first+dist[node];
                pq.push(make_pair(dist[g[node][i].second],g[node][i].second));
            }
        }
    }
}
int main()
{
    ll t,v,m,x,y,d;
    cin>>t;
    while(t--)
    {
        cin>>v>>m;
        for(ll i=0;i<10005;i++)
        {
            dist[i]=LLONG_MAX;
            g[i].clear();//clear previously made vector
        }
        for(ll i=0;i<m;i++)   //making adjacency list
        {
            cin>>x>>y>>d;
            g[x].push_back(make_pair(d,y));
        }
        cin>>x>>y;
        djikstra(x);
        if(dist[y]!=LLONG_MAX)
            cout<<dist[y]<<endl;
        else
            cout<<"NO\n";
    }
    return 0;
}
