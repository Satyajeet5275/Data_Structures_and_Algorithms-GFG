//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    // vector<vector<int>> adjList(int v, vector<int> adj[])
    // {
    //     vector<vector<int>> ans(v);
    //     for(int x=0;x<adj->size();x++)
    //     {
    //         int u=adj[x][0];
    //         int v=adj[x][1];
    //         ans[u].push_back(v);
    //     }
    //     return ans;
    // }
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        // vector<vector<int>> ad=adjList(v,adj);
        vector<int> bfs;
        vector<int> vis(v,0);
        queue<int> que;
        que.push(0);
        vis[0]=1;
        while(!que.empty())
        {
            int node=que.front();
            que.pop();
            bfs.push_back(node);
            
            for(auto x:adj[node])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    que.push(x);
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends