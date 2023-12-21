//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &rating) {
        // code here
        vector<int> left(n,1);
        vector<int> right(n,1);

        for(int i=1;i<n;i++)
        {
          if(rating[i]>rating[i-1] && left[i]<=left[i-1]) {
            left[i]=left[i-1]+1;
          } 
        }
        for(int i=n-2;i>=0;i--)
        {
          if(rating[i]>rating[i+1] && right[i]<=right[i+1])         {
            right[i]=right[i+1]+1;
          }
        }
        int totalCandies=0;
        for(int i=0;i<left.size();i++)
        {
          totalCandies+=max(left[i],right[i]);
        }
        return totalCandies;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends