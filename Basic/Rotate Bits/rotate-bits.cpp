//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
vector <int> rotate (int n, int d)
        {
            vector <int> ans;
            
            d = d%16;
            
            ans.push_back(((n<<d)|(n>>(16-d)))&((1<<16)-1));
            ans.push_back(((n>>d)|(n<<(16-d)))&((1<<16)-1));
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends