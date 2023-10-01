//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    vector<int> topoSort(int N,vector<vector<int>>& adj){
        vector<int> indegree(N);
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<N;i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        for(int i=0;i<N;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        return ans;
    }
    public:
    string findOrder(string dic[], int N, int K) {
        //code here
        vector<vector<int>> adj(K);
        for(int i=0;i<N-1;i++){
            string s1=dic[i];
            string s2=dic[i+1];
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s2[j]!=s1[j]){
                    adj[(s1[j]-'a')].push_back((s2[j]-'a'));
                    break;
                }
            }
        }
        // cout<<adj.size();
        vector<int> topo=topoSort(K,adj);
        string ans;
        for(int x:topo){
            ans.push_back((char)(x+'a'));
        }
        // cout<<ans;
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends