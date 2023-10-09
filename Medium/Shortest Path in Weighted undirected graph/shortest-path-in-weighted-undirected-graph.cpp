//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        
        vector<int> dist(n+1,1e9),parent(n+1);
        for(int i=1;i<=n;i++)   parent[i]=i;
        
        set<pair<int,int>> st;
        dist[1]=0;
        st.insert({0,1});
        
        while(!st.empty()){
            auto it=*st.begin();
            int node=it.second;
            int nDist=it.first;
           // cout<<node<<" ";
            st.erase({nDist,node});
            for(auto x:adj[node]){
                int adjNode=x.first;
                int adjDist=x.second;
                
                if(dist[adjNode]>(adjDist+nDist)){
                    if(dist[adjNode]!=1e9){
                        st.erase({adjDist,adjNode});
                    }
                    
                   // cout<<adjNode<<" "<<endl;
                    dist[adjNode]=(adjDist+nDist);
                    st.insert({(adjDist+nDist),adjNode});
                    parent[adjNode]=node;
                }
            }
            
        }
            if(dist[n]==1e9) return {-1};
            
            vector<int> path;
            int node=n;
            
            while(parent[node]!=node){
                path.push_back(node);
                node=parent[node];
            }
            path.push_back(1);
            reverse(path.begin(),path.end());
            return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends