//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int i,int t, int &n,vector<int> &cost,vector<vector<int>> &dp){
        if(i>=n)    
            return 0;
        
        if(dp[i][t]!=-1)    return dp[i][t];
        
        int np=solve(i+1,t,n,cost,dp);
        int p=0;
        if(t>=cost[i]){
            int cashback = floor((9.0 / 10) * cost[i]);
            p=1+solve(i+1,t-(cost[i]-cashback),n,cost,dp);
        }
        
        return dp[i][t]=max(np,p);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        // sort(begin(cost),end(cost));
        vector<vector<int>> dp(n,vector<int>(total+1,-1));
        return solve(0,total,n,cost,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends