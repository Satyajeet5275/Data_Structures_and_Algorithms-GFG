//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void solve(int ind,vector<int>& nums,set<vector<int>>& ans)
    {
        if(ind>=nums.size())
        {
            ans.insert(nums);
            return ;
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);
            solve(ind+1,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> ans;
        solve(0,arr,ans);
        // sort(ans.begin(),ans.end());
        vector<vector<int>> op;
        for(auto x:ans){
            op.push_back(x);
        }
        return op;
    }
};

// 1  1  2




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends