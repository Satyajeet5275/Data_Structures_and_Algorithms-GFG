//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        dist[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto it=*st.begin();
            int node=it.second;
            int nodeDist=it.first;
            st.erase({nodeDist,node});
            for(auto x:adj[node]){
                int adjNode=x[0];
                int adjDist=x[1];
                
                if(dist[adjNode]>(nodeDist+adjDist)){
                    // if(dist[adjNode]!=1e9){
                    //     st.erase({dist[adjNode],adjNode});
                    // }
                    
                    st.insert({(nodeDist+adjDist),adjNode});
                    dist[adjNode]=(nodeDist+adjDist);
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends