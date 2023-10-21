//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> vis(V,0);
        set<pair<int,int>> st;
        st.insert({0,0});
        int cost=0;
        while(!st.empty()){
            auto it=*st.begin();
            int dist=it.first;
            int node=it.second;
            st.erase({dist,node});
            if(vis[node]==1) continue;
            vis[node]=1;
            cost+=dist;
            // cout<<node<<" - "<<cost <<endl;
            for(auto x:adj[node]){
                int adjNode=x[0];
                int adjDist=x[1];
                
                if(vis[adjNode]!=1){
                    st.insert({adjDist,adjNode});
                }
            }
        }
        return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends