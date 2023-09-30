//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool dfs(int node,vector<int>& vis,vector<int> adj[]){
    int clr=vis[node];
    for(int i=0;i<adj[node].size();i++){
        int x=adj[node][i];
        if(vis[x]!=-1 && vis[x]==clr) return false;
        else if(vis[x]==-1){
            vis[x]=!clr;
            if(dfs(x,vis,adj)==false) return false;
        }
    }
    return true;
}
    bool isBipartite(int n,vector<int> adj[]) {
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                vis[i]=0;
                if(dfs(i,vis,adj)==false) return false;
            }
        }
        return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends