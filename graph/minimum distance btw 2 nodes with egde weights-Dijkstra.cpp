//graph is 2d matrix
//If in matrix, value at (2,3) =5 means on edge (2->3) weight is 5
//refer
//https://www.codingame.com/playgrounds/1608/shortest-paths-with-dijkstras-algorithm/dijkstras-algorithm

//Pass here
//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1



int nextMinDistance(int dist[],bool vis[],int V,int src){
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<V;i++){
        if(vis[i]==false && dist[i]<=min){
                min=dist[i];
                min_index=i;
        }
    }
    return min_index;
}


void dijkstra(vector<vector<int>> graph, int src, int V)
{
    int dist[V];
    //distance of source to any vertex i, inisiatized to inf except the source
    bool vis[V];
     for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, vis[i] = false; 
        
    dist[src]=0;
    //source distance is kept minimum
    
    for(int count =1;count<=V;count++){
        //index of next node with minimum distance from source which is unvisited
        //for the first call of nextMinDistance src will return as u as all others are inf.
         int u=nextMinDistance(dist,vis,V,src);
   
        //making 'u' visited 
        vis[u]=true;
        
        
        //updating distances of neighbours of 'u'
        // Update dist[v] only if it is not visited, there is an edge from  
         // u to v, and total weight of path from src to  v through u is  
         // smaller than current value of dist[v] 
         //path_distance of v=dist[u]+graph[u][v]
        for(int v=0;v<V;v++){
            if(!vis[v]&&graph[u][v] && dist[u]+graph[u][v]<dist[v]  )
                    dist[v]=dist[u]+graph[u][v];
        }
    }
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}