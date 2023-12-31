//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long factorsOf(long long n)
    {
        long long sum=1;
        for(long long i=2;i*i<=n;i++)
        {
            if(n%i==0) 
            {
                sum+=i;
                if(n/i!=i)
                    sum+=n/i;
            }
        }
        return sum;
    }
    int isPerfectNumber(long long N) {
        // code here
        if(N==1) return 0;
        long long factSum=factorsOf(N);
        // cout<<factSum;
        return (N==factSum);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends