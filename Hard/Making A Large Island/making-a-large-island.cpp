//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet
{
    public:
        vector<int> parent;
        vector<int> rank;
        vector<int> size;
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            size.resize(n+1,1);
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
            return parent[node]=(find_parent(parent[node]));
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
            else {  
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0) continue;
                for(int i=0;i<4;i++){
                    // cout<<"jdjd";
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n){
                        if(grid[nr][nc]==1){
                        // cout<<" in";
                            
                        int node=r*n+c;
                        int adjNode=nr*n+nc;
                        ds.union_by_size(node,adjNode);
                        }
                    }
                }
            }
        }
        int mx=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) continue;
                set<int> comp;
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        comp.insert(ds.find_parent(nr*n+nc));
                    }
                }
                int total=0;
                for(auto x:comp){
                    total+=ds.size[x];
                    // cout<<ds.size[x]<< " ";
                }
                // cout<<comp.size()<<" sz";
                mx=max(mx,total+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.find_parent(i)]);
            // cout<<ds.size[ds.parent[i]]<<", ";
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends