//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        // Code here 
     int target = img[sr][sc];
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img[i][j]!=0)
                {
                    vis[i][j]=img[i][j];
                }
            }
        }

        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=color;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow=row+dx[i];
                int ncol=col+dy[i];

                if( nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    img[nrow][ncol]==target && vis[nrow][ncol]!=color )
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=color;
                }
            }
        }
        return vis;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends