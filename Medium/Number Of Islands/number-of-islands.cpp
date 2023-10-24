//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
    public:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            size.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i]=i;
            }
        }
        int find_parent(int node)
        {
            if(parent[node]==node)
                return node;
            parent[node]=find_parent(parent[node]);
            return(find_parent(parent[node]));
        }
        void union_by_rank(int u,int v)
        {
            int pv = find_parent(v);
            int pu = find_parent(u);
            if(pv==pu)  
                return;
            if(rank[pv]<rank[pu])
            {
                parent[pv]=pu;
            }
            else if(rank[pv]>rank[pu])
            {
                parent[pu]=pv;
            }
            else
            {
                parent[pv]=pu;
                rank[pu]++;
            }
        }
        void union_by_size(int u,int v)
        {
            int pv = find_parent(v);
            int pu = find_parent(u);
            if(pv==pu)  
                return;

            if(size[pv]<size[pu])  {
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
            else {      //if(size[pv]>size[pu])
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        vector<int> ans;
        int dir_x[4] = {-1,0,1,0};
        int dir_y[4] = {0,-1,0,1};
        for(auto it:operators)
        {
            int row = it[0];
            int col = it[1];
            if(vis[row][col]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            for(int i=0;i<4;i++)
            {
                int new_row = row + dir_x[i];
                int new_col = col + dir_y[i];
                if(new_row >= 0 && new_row < n && new_col >=0 && new_col < m && vis[new_row][new_col])
                {
                    int currnode = row*m + col;
                    int adjnode = new_row * m + new_col;
                    if(ds.find_parent(currnode) != ds.find_parent(adjnode)){
                        cnt--;
                        ds.union_by_size(currnode,adjnode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends