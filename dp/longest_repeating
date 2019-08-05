#include <bits/stdc++.h>
using namespace std;

int solve(string s,int start,int end,vector<vector<int>> & dp){
  //  cout<<"fhvgjk"<<endl;
    
    if(start>=s.size()|| end>=s.size()) return 0;
    if(dp[start][end]>=0) return dp[start][end];
    if(s[start]==s[end] && start!=end){
        dp[start][end]= 1+solve(s,start+1,end+1,dp);
    }
    else{
        dp[start][end]=max(solve(s,start,end+1,dp),solve(s,start+1,end,dp));
    }
    return dp[start][end];
}
int main() {
    int t;
    cin>>t;
    while(t--){
         int n;
        cin>>n;
        string s;
        cin>>s;
        vector<vector<int>> v;
        v.resize(s.size()+1);
        for(int i=0;i<v.size();i++) v[i].resize(s.size()+1);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                v[i][j]=-1;
            }
        }
        cout<<solve(s,0,0,v)<<endl;
    }
	return 0;
}
