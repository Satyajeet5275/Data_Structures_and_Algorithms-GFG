//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));;
        set<pair<int,pair<int,int>>> st;
        dist[0][0]=0;
        st.insert({0,{0,0}});
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        while(!st.empty()){
            auto it=*st.begin();
            int diff=it.first;
            int x=it.second.first;
            int y=it.second.second;
            st.erase({diff,{x,y}});
            if(x==n-1 && y==m-1) return diff;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int newDiff=max((abs(grid[x][y]-grid[nx][ny])),diff);
                    if(newDiff<dist[nx][ny]){
                        st.insert({newDiff,{nx,ny}});
                        dist[nx][ny]=newDiff;
                    }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends