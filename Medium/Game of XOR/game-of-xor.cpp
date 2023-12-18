//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int gameOfXor(int n , int arr[]) {
        // code here
      int val = 0;
      for(int i = 0 ; i<n;i++)
      {
          int tt = (i+1)*(n-i);  // this means that how many times a particular val is comming in subaarays
          if(tt&1) // if occurance is odd then do it
              val = val^arr[i];
      }
      return val;
     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends