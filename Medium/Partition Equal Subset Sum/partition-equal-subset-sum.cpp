//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool targetSum(int arr[], int n, int target) {
        vector<int> dp(target + 1);
        dp[0] = true;
        for(int i = 0; i < n; i++) 
            for(int t = target; t >= arr[i]; t--)
                dp[t] |= dp[t - arr[i]];
        return dp.back();
    }

    int equalPartition(int n, int arr[]) {
        int sum = accumulate(arr, arr + n, 0);
        if(sum & 1) return false;
        return targetSum(arr, n, sum / 2);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends