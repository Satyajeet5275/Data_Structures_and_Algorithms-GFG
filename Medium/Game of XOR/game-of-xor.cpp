//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
      int xor1=0;
      int preval=0;
      for(int i=0;i<N;i++)
      {
          int val=preval+(N-i);
          if(val%2!=0)
          {
              xor1=xor1^A[i];
          }
          preval+=(N-i-1)-i;
          
      }
      return xor1;
       
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