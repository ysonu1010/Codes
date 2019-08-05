#include <bits/stdc++.h>
using namespace std;
int solve(int n,int r,vector<vector<long long int>> &dp){
     if(n<r) return 0*1LL;
    if(r==0 || r==n) return 1*1LL;
    if(dp[n][r]>=0) return dp[n][r];
    dp[n][r]= (solve(n-1,r,dp)+solve(n-1,r-1,dp))%1000000007;
    return dp[n][r];
}

int main() {
	int t;
    cin>>t;
    while(t--){
         int n,r;
        cin>>n>>r;
        vector<vector<long long int>> v;
        v.resize(n+1);
        for(int i=0;i<v.size();i++) v[i].resize(r+1);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<r+1;j++){
                v[i][j]=-1*1LL;
            }
        }
        cout<<solve(n,r,v)<<endl;
    }
	
	return 0;
}
