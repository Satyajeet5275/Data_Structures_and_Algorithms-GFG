//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int rem,int arr[],vector<vector<int>>& dp,int n,int wt[])
        {
            if(ind>=n)
            {
                // if(rem%wt[ind]==0) return rem/wt[ind]*(arr[ind]);
                // else return -1e9;
                return 0;
            }
            if(dp[ind][rem]!=-1) return dp[ind][rem];
            int pick=INT_MIN;
            if(rem>=wt[ind])
                pick=arr[ind] + solve(ind,rem-wt[ind],arr,dp,n,wt);
            int nonpick=solve(ind+1,rem,arr,dp,n,wt);
    
            return dp[ind][rem]=max(pick,nonpick);
        }

    int knapSack(int N, int amount, int coins[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(amount+1,-1));
        int ans=solve(0,amount,coins,dp,N,wt);
        if(ans==-1e9) return 0;
        return ans;
        
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends