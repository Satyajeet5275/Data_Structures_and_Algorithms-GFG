//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
// class Solution
// {
// public:
//     map<int,int> mp;
//     int dx[4]={0,0,-1,1};
//     int dy[4]={-1,1,0,0};
//     void dfs(int x,int y,int clr,int count,vector<vector<int>>& grid){
//         grid[x][y]=clr;
//         mp[clr]=count;

//         for(int i=0;i<4;i++){
//                 int nx=x+dx[i];
//                 int ny=y+dy[i];
//                 if( nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() &&
//                     grid[nx][ny]==1 ){
//                         count++;
//                         dfs(nx,ny,clr,count,grid);
//                     }
//         }
//     }
//     int largestIsland(vector<vector<int>>& grid) {
//         mp.clear();
//         if(grid.size() == 0){
//             return 0 ;
//         }
//         int clr=2;
//         int n=grid.size(),m=grid[0].size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1){
//                     dfs(i,j,clr,1,grid);
//                     clr++;
//                 }
//             }
//         }
//         int maxi=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==0){
//                     int count=1;
//                     set<int> st;
//                     for(int k=0;k<4;k++){
//                         int nx=i+dx[k];
//                         int ny=j+dy[k];
//                         if( nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() &&
//                             grid[nx][ny]!=0 && st.count(grid[nx][ny])==0){
//                                 int adjClr=grid[nx][ny];
//                                 count+=mp[adjClr];
//                                 st.insert(adjClr);
//                             }
//                     }
//                     maxi=max(maxi,count);   
//                 }
//             }
//         }
//         return maxi;
//     }
// };

class Solution
{
public:
    int n, m;
    
    // To traverse four directions of grid
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, -1, 0, 1};
    
    // To check whether coordinate lies inside the grid
    bool isValid(int ni, int nj)
    {
        if(ni >= 0 && nj >= 0 && ni < n && nj < m)
            return true;
        return false;
    }
    
    // To calculate size of each island in the grid.
    // For every island we are using a key. We are filling the visited array with this key,
    // so that we can get the size of island easily afterwards.
    int dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis, int &key)
    {
        vis[i][j] = key;
        int sz = 1;
        for(int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            
            if(isValid(ni, nj) && !vis[ni][nj] && grid[ni][nj])
            {
                sz += dfs(ni, nj, grid, vis, key);
            }
        }
        
        return sz;
    }
    // main function
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        n = grid.size();
        m = grid[0].size();
        int mx = 0, key = 1;
        vector<vector<int>> vis(n+1, vector<int>(m+1, 0));
        map<int, int> mp;
        // Map stores key - size relation in it
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    key++;
                    int sz = dfs(i, j, grid, vis, key);
                    mp[key] = sz;
                    mx = max(mx, sz);
                }
            }
        }
        
        // now traverse grid and if you find any zero change it to one and
        // then observe what will be its impact on existing size of island.
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                {
                    int newSize = 1;
                    set<int> st;
                    for(int k = 0; k < 4; k++)
                    {
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        
                        if(isValid(ni, nj) && grid[ni][nj])
                        {
                            st.insert(vis[ni][nj]);
                        }
                    }
                    for(auto it : st)
                    {
                        newSize += mp[it];
                    }
                    mx = max(mx, newSize);
                }
            }
        }
        
        // return maximum size island.
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