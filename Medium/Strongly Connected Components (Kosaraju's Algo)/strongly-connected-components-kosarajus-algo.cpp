//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj,stack<int>& st){
        vis[node]=1;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]) dfs(adjNode,vis,adj,st);
        }
        st.push(node);
    }
    void dfs1(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]) dfs1(adjNode,vis,adj);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,vis,adj,st);
        }
        
        vector<vector<int>> adjTrans(n);
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(int adjNode:adj[i]){
                adjTrans[adjNode].push_back(i);
            }
        }
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]) {
                dfs1(node,vis,adjTrans);
                scc++;
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends