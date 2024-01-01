//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
        // Code here.
        int n=arr.size();
        if(n%2!=0) return false;
        map<int,int> mp;
        int zero=0;
        for(int x:arr){            
            if(x%k==0){
                zero++;
                continue;
            }
            int rem=x%k;
            int req=k-rem;
            if(mp.count(req)){
                if(mp[req]==1) mp.erase(req);
                else mp[req]--;
            }
            else{
                mp[rem]++;
            }
        }
        return mp.size()==0 && zero%2==0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends