//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends

// class Solution{
//     public:
//     long long mod=1e9+7;
//     long long solve(int i,int n,int k){
//         if(n<=0){
//             if(n==0 && i<k)  return 1;
//             return 0;
//         }
//         if(i>=k) return 0;
        
//         long long pick1=0,pick2=0,nonpick=0;
        
//         for(int j=1;j<=k;j++){
//             if(i==j) continue;
//             nonpick+=solve(j,n,k);
//             if(n-1 >= 0)   pick1+=solve(j,n-1,k);
//             if(n-2 >= 0)   pick2+=solve(j,n-2,k);
//         }
//         return (pick1+pick2+nonpick);
//     }
//     long long countWays(int n, int k){
//         // code here
//         long long ways=solve(1,n,k);
//         return ways;
//     }
// };

class Solution {
public:
    long long countWays(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k + k * (k - 1) % 1000000007;

        long long mod = 1000000007;
        long long same = k;
        long long diff = (k%mod * (k - 1) % mod)%mod;
        long long total = (same %mod+ diff%mod) % mod;

        for (long long i = 3; i <= n; i++) {
            same = diff % mod;
            diff = (total % mod * (k - 1) % mod) % mod;
            total = (same%mod + diff%mod) % mod;
        }

        return total ;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends