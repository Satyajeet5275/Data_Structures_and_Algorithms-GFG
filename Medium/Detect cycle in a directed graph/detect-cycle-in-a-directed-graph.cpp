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
      


bool dfs(int node, vector<int> &vis, vector<int> adj[]){
        vis[node]=1;
        
        for(auto child: adj[node]){
            if(vis[child]==0){ //child node not visited yet
                if(dfs(child,vis,adj)){
                    return true; //returning true if child node return presence of cycle
                }
            }
            
            else if(vis[child]==1){ //node is still under processing and appeared again
                return true; //then there is back edge, finally cycle
            }
        }
        
        vis[node]=2; //marks evaluation is complete
        return false;
    }
   public: 
    
    bool isCyclic(int v, vector<int> adj[]) {
        // When graph is directed, our undirected approach fails whose pictorial rep has been attached
        
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                if(dfs(i,vis,adj)){
                    return true;
                }
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