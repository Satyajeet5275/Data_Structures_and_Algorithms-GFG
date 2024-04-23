//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
     int fn(int n, vector<int> &dp) {
    int mod = 1e9+7;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (dp[n] != 0) return dp[n];
    int ans = (fn(n - 1, dp) % mod + fn(n - 2, dp) % mod) % mod;
    return dp[n] = ans;
}
  public:
    int firstElement(int n) {
        // code here
           vector<int> dp(n + 1, 0);
    int result = fn(n, dp);
    return result;


    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends