//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        
map<int, int> freq;
for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
}
vector<int> duplicates;
for (auto pair : freq) {
    if (pair.second > 1) {
        duplicates.push_back(pair.first);
    }
}
// sort(duplicates.begin)
vector<int> result;
result.push_back(-1);
if (duplicates.empty()) {
    return result;
} else {
    return duplicates;
}
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends