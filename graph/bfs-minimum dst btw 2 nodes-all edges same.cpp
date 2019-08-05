#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int>graph[],bool vis[],int num1,int num2,int v){
    queue<int> q;
    q.push(0); 
    vis[0]=true;
    int dis[v]={0};//distance of all nodes is initially zero
    //this dis array stores level-wise distance of each node
        while(!q.empty()){
            int front=q.front();
            q.pop();
            cout<<front<<" ";
                    for(auto itr=graph[front].begin();itr!=graph[front].end();itr++){
                        if(!vis[*itr]){
                            q.push(*itr);
                            vis[*itr]=true;
                            dis[*itr]=dis[front]+1;
                            //distance of child =distance of parent+1;
                        }
                    }
        }
        cout<<endl;
     
       
            cout<<dis[num2]-dis[num1]<<" ";
            
}
    

int main() {
    int v,e;
    cin>>v>>e;
    vector<int> graph[v];
    for(int i=0;i<e;i++){
        int start,end;
        cin>>start>>end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    bool vis[v];
    for(int i=0;i<v;i++){
        vis[i]=false;
    }
    int num1,num2;
    cin>>num1>>num2;
    bfs(graph,vis,num1,num2,v);
	return 0;
}