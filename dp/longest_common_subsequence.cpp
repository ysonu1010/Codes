#include <bits/stdc++.h>
using namespace std;

int solve(string s1,string s2,int n1,int n2,vector<vector<int>> &dp){
    if(n1==0 || n2==0) return 0;
    if(dp[n1-1][n2-1]>=0) return dp[n1-1][n2-1];
	//last elements same
    if(s1[n1-1]==s2[n2-1])
        dp[n1-1][n2-1]= 1+solve(s1,s2,n1-1,n2-1,dp);
    else if(s1[n1-1]!=s2[n2-1])//last elements different
        dp[n1-1][n2-1]= max(solve(s1,s2,n1,n2-1,dp),solve(s1,s2,n1-1,n2,dp));
    return dp[n1-1][n2-1];   
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n1,n2;
	    cin>>n1>>n2;
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	vector<vector<int>> dp;
	dp.resize(n1);
	for(int i=0;i<n1;i++) dp[i].resize(n2);
	for(int i=0;i<n1;i++)
	    for(int j=0;j<n2;j++)
	        dp[i][j]=-1;
	cout<<solve(s1,s2,n1,n2,dp)<<endl;    
	}
	return 0;
}
