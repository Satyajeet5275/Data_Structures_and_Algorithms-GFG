//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// const int mod=1e5;
// const int N = 1e5;
// class Solution {
//   public:
//     int dp[N][N];
//     int solve(int i,vector<int> &arr,int start,int end)
//     {
        
//         if(start==end) return 0;
//         if(start>end || i>=arr.size()) return 1e6;
//         if(dp[i][start]!=-1) return dp[i][start];
//         int notpick=solve(i+1,arr,start,end);
//         int pick=1+solve(i,arr,(start*arr[i])%mod,end);
        
//         return dp[i][start]=min(notpick,pick);
//     }
//     int minimumMultiplications(vector<int>& arr, int start, int end) {
//         // code here
//         memset(dp,-1,sizeof(dp));
//         return solve(0,arr,start,end);
//     }
// };

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end)return 0;
        int mod=1e5;
        vector<bool> vis(mod);
        queue<pair<int,int>>q;
        q.push({0,start});
        vis[start]=1;
        while(!q.empty()){
            int level=q.front().first;
            int temp=q.front().second;
            q.pop();
            for( int i=0;i<arr.size();i++)
            {
                int prod=(temp*arr[i])%mod;
                if(prod==end)return level+1;
                if(vis[prod])continue;
                q.push({level+1,prod});
                vis[prod]=1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends