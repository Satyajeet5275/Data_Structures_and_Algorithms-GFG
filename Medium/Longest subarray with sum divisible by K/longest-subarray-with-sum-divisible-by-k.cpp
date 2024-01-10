//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
 int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int, int> mp;
	    mp[0] = -1;
	    int res = 0;
	    int sum = 0;
	    for(int i=0; i<n; ++i){
	       // +k is additionally done to handle the negative numbers
	        sum+=(arr[i]%k+k);
	        sum%=k;
	       // If the current modulus value(sum) has already been present, then it means,
              // if we exclude till that index then the sum after excluding will be divisible by k.
	        if(mp.find(sum)!=mp.end()){
	            res = max(res, i-mp[sum]);
	        }else{
	            mp[sum] = i;
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends