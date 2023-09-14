//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private: int mod=1e9+7;
	public:
	int solve(int i,int target,int *arr,int& n,vector<vector<int>>& dp)
	{
	    if(i==n)
	    {
	        if(target==0) return 1;
    	    return 0;
	    }
	    
	    if(dp[i][target]!=-1) return dp[i][target];
	    
	    int pick=0,nonpick=0;
	    nonpick=solve(i+1,target,arr,n,dp);
	    if(!(target-arr[i]<0))
	    pick=solve(i+1,target-arr[i],arr,n,dp);
	    
	    return dp[i][target]=(nonpick+pick)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,sum,arr,n,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends