//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution{
// 	public:
// 	int solve(int ind,int prev,int n,int arr[],vector<vector<int>> &dp){
// 	    if(ind==n) return 0;
// 	    if(dp[ind][prev]!=-1) return dp[ind][prev];

// 	    if(prev==n || arr[prev]<arr[ind]) return dp[ind][prev]=max(arr[ind]+solve(ind+1,ind,n,arr,dp),solve(ind+1,prev,n,arr,dp));
// 	    else return dp[ind][prev]=solve(ind+1,prev,n,arr,dp);
// 	   // return dp[ind][prev]=max(nonPick,pick);
// 	}
// 	int maxSumIS(int arr[], int n)  
// 	{  
// 	    // Your code goes here
// 	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
// 	    return solve(0,n,n,arr,dp);
// 	}  
// };

class Solution{
 int dp[1001][1001] ;
 public:
 int solve( int arr[] , int n , int i , int pre)
    {
        if( i == n ) return 0 ;
        if( dp[i+1][pre+1] != -1 ) return dp[i+1][pre+1];
        if( pre == -1 or arr[pre] < arr[i] )
        {
            return dp[i+1][pre+1] = max( arr[i] + solve(arr , n , i+1 , i ) , solve(arr,n, i+1 , pre )) ;
        }
        else{
            return dp[i+1][pre+1] = solve( arr , n , i+1 , pre ) ;
        }
    }   
 int maxSumIS(int arr[], int n)  
 {  
     // Your code goes here
  memset(dp , -1 , sizeof(dp)) ;
  return solve( arr , n , 0 , -1 ) ;
 }  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends