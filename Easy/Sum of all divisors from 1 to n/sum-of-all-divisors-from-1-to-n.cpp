//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    // long long divisorSum(int n){
    //     long long ans=0;
    //     for(int i=1;i<=n;i++){
    //         if(n%i==0) ans+=i;
    //     }
    //     return ans;
    // }
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long ans=0;
        for(int i=1;i<=N;i++){
            // ans+=divisorSum(i);
            ans+=i*(N/i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends