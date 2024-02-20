//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        int ns = s.size();
        
        vector<bool> dp(ns+1, 0);
        dp[0] = 1;
        
        for(int i = 0; i<ns; i++){
            if(!dp[i]) continue;
            
            string ss;
            for(int j = i; j<ns; j++){
                ss += s[j];
                for(auto _: dictionary){
                    if(ss==_) {dp[j+1] = 1; break;}
                }
            }
        }
        
        return dp[ns];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends