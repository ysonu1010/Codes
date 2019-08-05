#include <bits/stdc++.h>
using namespace std;
struct subsets{
    int parent;
    int rank;
};
int find(subsets subset[], int i)  
{  
    // find root and make root as parent of i  
    // (path compression) 
    //on each call to find, path compression take place
    //In the same tree, parent of i is assigned as the root of current set
    //or subtree having root as i, is made direct child of the tree's main root 
    if (subset[i].parent != i)  
        subset[i].parent = find(subset, subset[i].parent);  
  
    return subset[i].parent;  
} 

void Union(subsets subset[], int x, int y)  
{  
    int xroot = find(subset, x);  
    int yroot = find(subset, y);  
    
    //when x and y lies in two trees of different rank(or height, its not always height as height changes on call to find(length compression))
    //then to make the resultant tree with minimum rank or height, small tree is attached under larger tree
    //initital rank or height og each element of set(all the vertices of graph are different element of set, or they are different individual tree with height =0)
    // Attach smaller rank tree under root of high  
    // rank tree (Union by Rank)  
    if (subset[xroot].rank < subset[yroot].rank)  
        subset[xroot].parent = yroot;  
    else if (subset[xroot].rank > subset[yroot].rank)  
        subset[yroot].parent = xroot;  
  
    // If ranks are same, then make one as root and  
    // increment its rank by one  
    else
    {  
        subset[yroot].parent = xroot;  
        subset[xroot].rank++;  
    }  
}  

int myComp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)  
{  
    return a.second < b.second;  
} 

int KruskalMST(vector<pair<pair<int,int>,int>> &graph,subsets subset[])  
{  
    int result=0;

    //SORTING EDGES of graph AS PER WEIGHTS
    sort(graph.begin(),graph.end(),myComp); 
   
    int i = 0; // An index variable, used for sorted edges
    while (i < graph.size())  
    {  
        auto edge=graph[i];
        int u=edge.first.first;
        int v=edge.first.second;
      
  
        int x = find(subset, u);  
        int y = find(subset, v);

        //if parent of u or (root of tree) containing u is same as root of tree containing
        //v then then union of this edge(u-v) will form a cycle in the same tree, but here we dont want cycle in MST
        //so ignore the case 
        if (x != y)  
        {  
            result+= edge.second;  
            Union(subset, x, y); 
        }  
      
        i++;
    }  
   return result;  
}  



int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<pair<pair<int,int>,int>> graph;
	    subsets subset[n+1];
	    for (int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            int a;
    	        cin>>a;
    	        graph.push_back({{i,j},a});
    	        
	        }
          subset[i].parent=i;
          subset[i].rank=0;
	    }
	    cout<<KruskalMST(graph,subset)<<endl;
	}
	
}