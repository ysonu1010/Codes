#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

void dfs(int s, vector<int> g[], bool vis[])
{
    //it is same as iterative bfs just that stack is used in place of queue
    stack<int> st;
    st.push(s);
    vis[s]=true;
    //make "visited" as soon as node is visited
    //no node should enter queue twice.
    while(!st.empty()){
        int a=st.top();
        st.pop();
        cout<<a<<" ";
        for(auto it=g[a].begin();it!=g[a].end();it++){
            if(!vis[*it]){
                st.push(*it);
                vis[*it]=true;
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