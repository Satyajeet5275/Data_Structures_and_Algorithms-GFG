//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, vector<int> adj_list[], int vis[]){
        // if node is already visited when doing dfs then there is a cycle in the graph
        if(vis[node]) return false;
        // marking visited of node as 1 during dfs
        vis[node] = 1;
        // performing dfs on all the adjacent nodes of graph
        for(auto &it: adj_list[node]){
            dfs(it, adj_list, vis);
        }
        return true;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        // for a tree number of edges must be n-1 where n is the nnumber of nodes
        if(m != n-1) return 0;
        // edge case where we dont have any edges
        if(n == 1) return 1;
        // creating an adjacency list for faster access of adjacent nodes
        vector<int> adj_list[n];
        for(auto& it: adj){
            // if self loop then return 0 since trees don't contain self loops
            if(it[0] == it[1]) return 0;
            // putting adjacent elements in adj list
            adj_list[it[0]].push_back(it[1]);
            adj_list[it[1]].push_back(it[0]);
        }
        // creating a visited array to store the visited elements in dfs
        int vis[n] = {0};
        // checking whether there is a cycle in the graph using dfs and visited
        bool tree = dfs(adj[0][0],adj_list, vis);
        // if tree is false that means there is a cycle in the graph
        if(tree == false) return false;
        // if not all nodes are visited in the dfs of any node ( here adj[0][0] ) 
        // then the graph has more than 1 connected component which implies it is not
        // a tree.
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) return 0;
        }
        // after all the above cases are taken care of we can conclude given graph is a tree
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends