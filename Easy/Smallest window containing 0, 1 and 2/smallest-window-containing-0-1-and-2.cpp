//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int n=s.length();
        int zero=-1,one=-1,two=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero=i;
            }
            else if(s[i]=='1'){
                one=i;
            }
            else if(s[i]=='2'){
                two=i;
            }
            if(zero!=-1 && one!=-1 && two!=-1){
                int start=min(zero,min(one,two));
                int end=max(zero,max(one,two));
                int dist=(end-start)+1;
                mini=min(mini,dist);
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends