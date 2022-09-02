#include <bits/stdc++.h>
using namespace std;
#define  INF 1e9+10;
void dijkstra_algo()
{
  int n,m;
    cin>>n>>m;      // number of node = n and number of edgs= m
    int u,v,w;
    vector< vector< pair<int, int > > >adj(n);

    for(int i=0;i<m;i++)
    {
       cin>>u>>v>>w;
       adj[u].push_back({v,w});     //adj[u][0]= ,adj[u][1]= ,adj[u][2]= ,......
       adj[v].push_back({u,w});     //adj[v][0]= ,adj[v][1]= ,adj[v][2]= ,......

    }
    bool vis[n];
    for(int i=0;i<n;i++)vis[i]=false;

    int cost[n];
    for(int i=0;i<n;i++)cost[i]=-1;

    int parent[n];
    for(int i=0;i<n;i++)parent[i]=i;

    priority_queue< pair< int, int >,vector<pair<int,int>>,greater<pair<int,int> > >pq;
     // priority _queue ta first element is cost and  second element is node;
    pq.push({0,0});
    cost[0]=0;

    while(!pq.empty())
    {
         v = pq.top().second;
        w = pq.top().first;
        pq.pop();
        if(vis[v]==true)continue;
        vis[v]=true;
        for(pair <int ,int > x : adj[v])
        {
            if(vis[x.first]==true||(w+x.second>cost[x.first]&& cost[x.first]!=-1))
            continue;
            cost[x.first]=w+x.second;
            pq.push({w+x.second,x.first});
            parent[x.first]=v;
        }
    }
    for(int i=0;i<n;i++)
    cout<<cost[i]<<" ";
    cout<<endl;
    int destinstion =6;
    vector<int >path;
    while(parent[destinstion]!=destinstion)
    {
        path.push_back(destinstion);
        destinstion=parent[destinstion];

    }
    path.push_back(0);
    for(int i=path.size()-1;i>=0;i--)
    cout<<path[i]<<" ";

  
}

int main() {
    dijkstra_algo();
   
}
