
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
bool cyclicUtil(int u,vector<int> adj[],bool vis[],bool recStack[]){
    
        if(vis[u]==false){
            //since u is not visited, we visit it and also put it in recursion stack
                    vis[u]=true;
                recStack[u]=true;
                //now we check children of u for same
                for(auto itr=adj[u].begin();itr!=adj[u].end();itr++){
                    //if child is not visited, check same for children of this child
                    if(!vis[*itr]){
                        if(cyclicUtil(*itr,adj,vis,recStack)==true) return true;
                    }
                    
                    //if child is visited, and is in recursion stack, there is cycle
                    if(vis[*itr]){
                        if(recStack[*itr]) return true;
                    }
                    //if something is in recursion stack, that means its children are being examined.
                    //if some child point back to the same 'something' or can say 'its in recStack', that means its a cycle 
                }
    }
    recStack[u]=false; //in case of only one child 'u', and to remove items from rec stack in case we reach an end and there is no cycle, 
    //we recurse back and keep coming out of recursion stack. 
    //when all the children of given root u are examined, the recursiion stack should be empty, so it is.
    return false;
    
    // iterate for example:
    // 1->2->3
    // 1->4->3
    // case of no cycle
    
    //refer this video
    // https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
    
}

bool isCyclic(int V, vector<int> adj[])
{
    bool vis[V],recStack[V];
    for(int i=0;i<V;i++){
        vis[i]=false;
        recStack[i]=false;
    }

    //this loop is to manage the situation of disconnected graphs, where all the vertices are not in same graph
   for(int i=0;i<V;i++){
       if(cyclicUtil(i,adj,vis,recStack))
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

