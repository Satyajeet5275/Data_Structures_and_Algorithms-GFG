//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/
class Solution
{
    public:
    int mod = 1e9+7;
    int solve(int i, int j, string &s, string &t, int sLen, int tLen, vector<vector<int>>&dp){
        if(j==tLen){
            return 1;
        }
        if(i==sLen){
            return 0;
        }
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int match = 0, notMatch = 0;
        if(s[i]==t[j]){
            match = solve(i+1, j+1, s, t, sLen, tLen, dp) + solve(i+1, j, s, t, sLen, tLen, dp);
            match %= mod;
        }
        else {
            notMatch = solve(i+1, j, s, t, sLen, tLen, dp);
            notMatch %= mod;
        }
        
        return dp[i][j] = (match + notMatch)%mod;
    }
    
    int subsequenceCount(string s, string t)
    {
      int sLen = s.length();
      int tLen = t.length();
      
      vector<vector<int>> dp(sLen+1, vector<int>(tLen, -1));
      
      return solve(0, 0, s, t, sLen, tLen, dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends