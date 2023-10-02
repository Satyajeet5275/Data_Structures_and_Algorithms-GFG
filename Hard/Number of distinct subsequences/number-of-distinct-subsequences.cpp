//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
//Brute Force
//   void solve(int i,string& s,string& op,set<string>& st){
//       if(i==s.length()){
//           st.insert(op);
//           return;
//       }
//       solve(i+1,s,op,st);
//       op.push_back(s[i]);
//       solve(i+1,s,op,st);
//       op.pop_back();
     
//   }
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	   // set<string> st;
	   // string op="";
	   // solve(0,s,op,st);
	   // return st.size();
	   long long mod=1e9+7;
	   int n=s.length();
	   vector<int> dp(n+1);
	   dp[0]=1;
	   
	   map<char,int> mp;
	   
	   for(int i=1;i<=n;i++){
	       dp[i]=(dp[i-1]*2)%mod;
	       char ch=s[i-1];
	       if(mp.find(ch)!= mp.end()){
	           int j=mp[ch];
	           dp[i]=(dp[i]-dp[j-1]+mod)%mod;
	       }
	       mp[ch]=i;
	   }
	   return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends