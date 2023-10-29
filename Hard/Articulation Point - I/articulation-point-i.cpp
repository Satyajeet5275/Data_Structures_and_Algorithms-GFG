//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int timer=1;
    void dfs(int node,int parent,int tin[],int low[],vector<int>& ans,vector<int>& vis,vector<int>adj[]){
        vis[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        int child=0;
        for(auto adjNode:adj[node]){
            if(adjNode==parent) continue;
            else if(!vis[adjNode]){
                dfs(adjNode,node,tin,low,ans,vis,adj);
                low[node]=min(low[node],low[adjNode]);
                if(low[adjNode]>=tin[node] && parent!=-1){
                    ans[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[adjNode]);
            }
            if(child>1 && parent==-1)   ans[node]=1;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        int tin[n],low[n];
        vector<int> vis(n,0);
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,-1,tin,low,ans,vis,adj);
        }
        vector<int> op;
        for(int i=0;i<n;i++){
            if(ans[i]==1) op.push_back(i);
        }
        if(op.size()==0) return {-1};
        return op;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends