//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto x:adj[node])
            if(!vis[x])
                dfs(x,adj,vis);
    } 
    int numProvinces(vector<vector<int>> edge, int n) {
        // code here
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j && edge[i][j]==1) adj[i].push_back(j);
    
        vector<int> vis(n+1);
        int count=0;
    
        for(int i=0;i<n;i++){
            if (!vis[i]) {
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends