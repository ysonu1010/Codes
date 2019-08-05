
#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[])
{
    queue<int> q;
    q.push(s);
    vis[s]=1;
    //make "visited" as soon as node is visited
    //no node should enter queue twice.
    while(!q.empty()){
        
        int a=q.front();
        q.pop();
        cout<<a<<" ";
        
        for (auto it=adj[a].begin();it!=adj[a].end();it++){
                if(!vis[*it]){
                    q.push(*it);
                    vis[*it]=1;
                    //make "visited" as soon as node is visited
                     //no node should enter queue twice.
                }
        }
    }
    
    
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N];
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis);
        cout<<endl;
    }
}

}