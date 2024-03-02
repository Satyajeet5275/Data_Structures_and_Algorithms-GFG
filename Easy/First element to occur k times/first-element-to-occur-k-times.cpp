//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        unordered_map<int,int> ans; // Creation of hashmap
        for(int i=0;i<n;i++){
                ans[a[i]]++; // Increase the counter variable for every entry
                if(ans[a[i]]==k) return a[i]; // first element which reaches k is returned
        }
        return -1; // Else -1 is returned 
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends