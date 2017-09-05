#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>

using namespace std;
vector<int> v[100];
int vis[100]={0};
queue<int>q;
stack<int>stk;
void bfs(int s)
{
    q.push(s);
    cout<<s;
    vis[s]=1;
    while(!q.empty())
    {
        int temp=q.front();
        cout<<temp<<" ";
        q.pop();
        for(int i=0;i<v[temp].size();i++)
        {
            if(vis[v[temp][i]]==0)
            {
                q.push(v[temp][i]);
                vis[v[temp][i]]=1;
                //cout<<v[temp][i];

            }
        }
    }
    cout<<"q is empty";
}
void dfs(int s)
{
    stk.push(s);
    vis[s]=1;
    //cout<<s;
    while(!stk.empty())
    {
       int temp=stk.top();
       cout<<temp;
       stk.pop();
       for(int i=0;i<v[temp].size();i++)
       {
        if(vis[v[temp][i]]==0)
        {
           stk.push(v[temp][i]);
           vis[v[temp][i]]=1;
           //cout<<v[temp][i];
        }
        }
    }
    cout<<"stack is empty";
}
int main()
{
    int n,m,x,y,s,d; //n-> no. of nodes ,m->no of edges
    cout<<"enter the no. of vertices and edges"<<endl;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y; //x and y are nodes
        v[x].push_back(y);
        v[y].push_back(x);
    }
    scanf("%d %d",&s,&d);
    bfs(s);
    for(int i=0;i<n;i++)
    {
         vis[i]=0;
       printf("\n");
    }
    dfs(s);
    return 0;

}
