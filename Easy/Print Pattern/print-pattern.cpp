//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        // code here
        vector<int>v;
        if(N==0){
            v.push_back(N);
            return v;
        }
        else if(N<0){
            v.push_back(N);
            return v;
        } 
        else{
        int x=N;
        for(int i=0;i<(N/2)+1;i++){
            v.push_back(x);
            x=x-5;
            if(x<=0){
                v.push_back(x);
                break;
            }
        }
        
        for(int i =0;i<(N/2) +1;i++){
            
            x=x+5;
            v.push_back(x);
            if(x==N)break;
        }
        return v;}
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
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends