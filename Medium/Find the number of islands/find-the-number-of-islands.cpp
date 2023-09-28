//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void bfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i1=-1;i1<=1;i1++)
            {
                for(int j1=-1;j1<=1;j1++)
                {
                    int adjI=row+i1;
                    int adjJ=col+j1;
                    if( adjI>=0 && adjI<n && adjJ>=0 && adjJ<m &&
                        !vis[adjI][adjJ] && grid[adjI][adjJ]=='1' ){
                        vis[adjI][adjJ]=1;
                        q.push({adjI,adjJ});
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    bfs(i,j,vis,grid);
                    // cout<<i<<"-"<<j<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends