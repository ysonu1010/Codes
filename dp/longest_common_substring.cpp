#include <bits/stdc++.h>
using namespace std;
int solve(string x,string y,int n,int m,int count,vector<vector<int>> &dp){
    if(n==0 || m==0) return 0;
    if(dp[n-1][m-1]!=-1) return dp[n-1][m-1];
    if(x[n-1]==y[m-1]){
        count=solve(x,y,n-1,m-1,count+1,dp);
        dp[n-1][m-1]=count;
    }
    else{
        count=max(count,max(solve(x,y,n-1,m,0,dp),solve(x,y,n,m-1,0,dp)));
        dp[n-1][m-1]=count;
        
    }
    return dp[n-1][m-1];
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    vector<vector<int>> v;
	    v.resize(n);
	    for(int i=0;i<n;i++) v[i].resize(m);
	    for(int i=0;i<n;i++)
	        for(int j=0;j<m;j++) 
	            v[i][j]=-1;
	   
	    cout<<solve(s1,s2,n,m,0,v)<<endl;
	}
	return 0;
}