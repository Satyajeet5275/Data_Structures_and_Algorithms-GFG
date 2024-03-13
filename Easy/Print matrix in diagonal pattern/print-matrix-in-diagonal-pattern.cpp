//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         int cnt = 0;
         int n = mat.size();
         vector<int> ans;
         
         for(int i=0;i<n;i++){
             int index = i;
             if(cnt % 2 == 0){
                 // j ko increase
                 // index ko decrease
                 for(int j=0;j<=i;j++){
                     ans.push_back(mat[index][j]);
                     index--;
                 }
             }
             else{
                 index = i;
                 for(int j=0;j<=i;j++){
                     ans.push_back(mat[j][index]);
                     index--;
                 }
             }
             cnt++;
         }
         
         for(int i=1;i<n;i++){
             int index = i;
             if(cnt % 2 != 0){
                 for(int j=n-1;j>=i;j--){
                     ans.push_back(mat[index][j]);
                     index++;
                 }
             }
             else{
                 index = n-1;
                 for(int j=i;j<n;j++){
                     ans.push_back(mat[index][j]);
                     index--;
                 }
             }
             cnt++;
         }
         
         
         return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends