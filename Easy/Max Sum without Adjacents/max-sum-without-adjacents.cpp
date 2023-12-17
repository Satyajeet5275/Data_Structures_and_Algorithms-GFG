//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
int f(int n,int *arr,vector<int>& dp){
        if(n==0) return arr[0];
        if(n<0) return 0 ;
 
        if(dp[n]!=-1) return dp[n];
 
        //pick
        int pick = f(n-2,arr,dp) + arr[n];
 
        //not pick
        int notPick = f(n-1,arr,dp);
 
        return dp[n] = max(pick,notPick);
    }
    
// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n) {
        vector<int>dp(n,-1);
 
        return f(n-1,arr,dp);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends