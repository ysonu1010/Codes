bool cyclicUtil(int u,vector<int> adj[],bool vis[],int parent){
    
        vis[u]=true;
        for(auto itr=adj[u].begin();itr!=adj[u].end();itr++){
            if(!vis[*itr]){
                if(cyclicUtil(*itr,adj,vis,u)) return true;
            }
            //visited again means cycle
            else return true;
        }
        //means 'u' either has no children, or there is not cycle in any of its children and neibours
        //to check if any other starting point leads to cycle with 'u' we might have to access 'u' again so make it unvisited
        //as in the below example 
        //1->2->3
        //1->4->3
        //In this there is no cycle but 3 need to be visited again to check all possibility, need to make false while returning from 3 

        vis[u]=false;
        return false;
}

bool isCyclic(int V, vector<int> adj[])
{
     bool visited[V]={false};
   for(int i=0;i<V;i++){
       if(!visited[i])
       if(cyclicUtil(i,adj,visited,-1))
        return true;
   }
   return false;
   
}


int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}