#include <bits/stdc++.h>
using namespace std;
//bellman ford is used to find minimum distance of nodes from source in case there is negative weight of any side.
//BUT if there is any cycle in graph that contains atleat one negative edge, then we can never find minimum distance of nodes by any method.


int bellmanford(vector<vector<int>> graph,int src,int V,int e){
    vector<int> dist(V,INT_MAX);
    dist[src]=0;
    
    //refer abdul wari video
    //works like dijkistra algo but same iteration goes V-1 times to relax the edges as the relaxation is once in case of dijkistra algo
    //in this, after each i the minimum distance at each vertex reduces and get closer 
    //to minimum but it can become constant for all vertices even before V-1 iterations, but the loop still need to check till V-q
    //in case of negative weight cycle the minimum distances doesnt become contant even after V-1 iteration 
    //so we make one extra iteration and check if frther relaxation is possible. If possible means there is a negative weight cycle. 
    for(int i=1;i<=V-1;i++){
        for(int j=1;j<=e;j++){
            int u=graph[j][0];
            int v=graph[j][1];
            int weight=graph[j][2];
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
                dist[v]=dist[u]+weight;
        }
    }
    
    for(int j=1;j<=e;j++){
        int u=graph[j][0];
        int v=graph[j][1];
        int weight=graph[j][2];
        if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
            return 1;
    }
    
    return 0;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    vector<vector<int> > graph(e+1,vector<int>(3,0));
	   
	    for(int i=1;i<=e;i++){
	        int u,v,w;
	        cin>>u>>v>>w;
	        graph[i][0]=u;
	        graph[i][1]=v;
	        graph[i][2]=w;
	    }
	    cout<<bellmanford(graph,0,v,e)<<endl;
	}
	return 0;
}