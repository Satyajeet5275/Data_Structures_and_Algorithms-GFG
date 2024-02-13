//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
         long long mod = 1e9+7;
        long long ans = 0; 
        long long res  = 1;
        long long startingDigit = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                res = (res*startingDigit)%mod;
                startingDigit++;
            }
            ans = (ans + res)%mod;
            res = 1;
        }
        return ans%mod;
    }


};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends