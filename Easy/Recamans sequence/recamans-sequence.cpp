//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
         vector<int>ans;
       unordered_set<int>s;
       ans.push_back(0);
       s.insert(0);
       for(int i=1;i<n;i++)
       {
           int a=ans[i-1]-i;
           if(a<0||s.find(a)!=s.end())
           a=ans[i-1]+i;
           
           ans.push_back(a);
           s.insert(a);
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends