bool cyclicUtil(int u,vector<int> adj[],bool vis[],int parent){
    
        vis[u]=true;
        for(auto itr=adj[u].begin();itr!=adj[u].end();itr++){
            if(!vis[*itr]){
                if(cyclicUtil(*itr,adj,vis,u)) return true;
            }
            //this checks if the element which is already visited is the immediate parent or not, 
            //if it is immediate parent then its not a back edge but a undirected edge from child to 'parent'
            //if its not immediate parent then and is being visited again then its a cycle
            else if (*itr!=parent) return true;
        }
        return false;
}
bool isCyclic(vector<int> adj[], int V)
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