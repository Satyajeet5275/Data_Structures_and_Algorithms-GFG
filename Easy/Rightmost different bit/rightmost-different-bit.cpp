//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        if(m==n) return -1;
        int ind=1;
        while(m && n){
            int mBit=m&1;
            int nBit=n&1;
            if(nBit!=mBit) return ind;
            
            ind++;
            n=n>>1;
            m=m>>1;
        }
        if((m>0 && n<=0) || (m<=0 && n>0)) return ind;
        return -1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends