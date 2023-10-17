//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    vector<vector<int>> transitiveClosure(int n, 
    vector<vector<int>>& graph){
    // transitive property means whether a 
    // node i can reach node j if can then 1
    // using Warshall's Algo
    vector<vector<int>> trans=graph;
    // since every vertex is reachable to itself
    for(int i=0;i<n;i++)
        trans[i][i]=1;
    // using Warshall's algo to see whether can
    // reach through an intermediate value node
    for(int val=0;val<n;val++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                trans[i][j]=trans[i][j]||(trans[i][val]
                &&trans[val][j]);
            }
        }
    }
    return trans;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends