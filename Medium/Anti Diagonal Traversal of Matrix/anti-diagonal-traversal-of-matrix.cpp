//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        unordered_set<string>st;
        int n = matrix.size();
        vector<int>res;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                string s = to_string(i) + "#" + to_string(j);
                if(st.find(s) == st.end()){
                    res.push_back(matrix[i][j]);
                    st.insert(s);
                }
                
                int r = i + 1, c = j - 1;
                
                while(r < n && c >= 0){
                    string t = to_string(r) + "#" + to_string(c);
                        if(st.find(t) == st.end()){
                        res.push_back(matrix[r][c]);
                        st.insert(t);
                    }
                    ++r;
                    --c;
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends