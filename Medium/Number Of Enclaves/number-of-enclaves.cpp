//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n=grid.size(),m=grid[1].size();
        if(m==1 || n==1 || m==2 || n==2) return 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int count=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1) count++;
                }
            }

        for(int i=0;i<n;i++){
                if(grid[i][0]==1 && vis[i][0]!=2 ) {
                    vis[i][0]=2;
                    q.push({i,0});
                }
                if(grid[i][m-1]==1 && vis[i][m-1]!=2){
                    vis[i][m-1]=2;
                    q.push({i,m-1});
                }
        }
        for(int i=0;i<m;i++){
                if(grid[0][i]==1 && vis[0][i]!=2){
                    vis[0][i]=2;
                    q.push({0,i});
                }
                if(grid[n-1][i]==1 && vis[n-1][i]!=2){
                    vis[n-1][i]=2;
                    q.push({n-1,i});
                }
        }
        count-=q.size();
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if( nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol]==1 && vis[nrow][ncol]!=2 ){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=2;
                    count--;
                }
            }
        }
            return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends