#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

void dfs(int s, vector<int> g[], bool vis[])
{
    cout<<s<<" ";
    vis[s]=true;
    
        for(auto it=g[s].begin();it!=g[s].end();it++){
                if(!vis[*it])   {
                    dfs(*it,g,vis);
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
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            //undirected graph
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0,g,vis);
        
        cout<<endl;
    }
}