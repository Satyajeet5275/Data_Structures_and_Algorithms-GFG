//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int solve(int n){
        // if(n==0) return 1;
        
        // int step1=INT_MAX;
        // int step2=1+solve(n-1);
        // if(n/2>0) step1=1+solve(n/2);
        // return min(step1,step2);
        if (n == 0) return 0;

        // if (dp[n] != -1)
        //     return dp[n];
    
        int result;
        if (n % 2 == 0)
            result = minOperation(n / 2) + 1;
        else
            result = minOperation(n - 1) + 1;
    
        // dp[n] = result;
        return result;
    }
    
    int minOperation(int n)
    {
        if(n<=1) return n;
        return solve(n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends