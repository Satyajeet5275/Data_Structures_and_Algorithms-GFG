//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> destination) {
        // code here
        if(src==destination) return 0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        vis[src.first][src.second]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src.first,src.second}});
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            int dist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if( nx>=0 && nx<n && ny>=0 && ny<m &&
                    grid[nx][ny]==1 && vis[nx][ny]>(dist+1)){
                        if(nx==destination.first && ny==destination.second){
                            return dist+1;
                        } 
                        // cout<<nx<<"-"<<src.first<<","<<src.second<<"-"<<ny<<"  ";
                        
                        vis[nx][ny]=(dist+1);
                        q.push({dist+1,{nx,ny}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends