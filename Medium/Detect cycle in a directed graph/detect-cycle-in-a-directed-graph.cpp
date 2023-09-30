//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // bool check(int i,vector<int> adj[],vector<int>& vis){
    //     queue<int> q;
    //     q.push(i);
    //     vis[i]=1;
        
    //     while(!q.empty()){
    //         int node=q.front();
    //         q.pop();
            
    //         for(auto x:adj[node]){
    //             if(!vis[x]){
    //                 q.push(x);
    //                 vis[x]=1;
    //             }
    //             else if(vis[i]==1) return true;
    //         }
    //     vis[i]=2;
    //     }
    //     return false;
    // }
      bool dfs(int i,vector<int> adj[],vector<int>& vis){
        vis[i]=1;
            
        for(auto x:adj[i]){
            if(vis[x]==0){
                if(dfs(x,adj,vis)) return true;
            }
            else if(vis[x]==1) return true;
        }
        vis[i]=2;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends