//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    // static bool compair(vector<int> v1,vector<int> v2){
    //     if(v1[1]>v2[1]) return true;
    //     else if(v1[1]==v2[1] && v1[0]<v2[0]) return true;
    //     return false;
    // }
    // vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
    //     // code here
    //     map<int,int> mp;
    //     vector<vector<int>> ans;
    //     for(int x:arr){
    //         if(x==0) continue;
    //         mp[x]++;
            
    //         vector<vector<int>> a;
    //         for(auto y:mp){    
    //             a.push_back({y.first,y.second});
    //         }
    //         sort(a.begin(),a.end(),compair);
    //         int n1=min(k,(int)a.size());
    //         vector<int> tmp;
    //         for(int i=0;i<n1;i++){
    //             tmp.push_back(a[i][0]);
    //         }
    //         ans.push_back(tmp);
    //     }
    //     return ans;
    // }
    vector<vector<int>> kTop(vector<int>& arr, int N, int k) {
        vector<vector<int>> ans(N);
        unordered_map<int,int> m;
        set<pair<int,int>> s;
        for(int i=0;i<N;i++){
           auto it =  s.find({m[arr[i]],-1*arr[i]});
           if(it!=s.end()){
               s.erase(it);
           }
            m[arr[i]]++;
            s.insert({m[arr[i]],-1*arr[i]});
             if(s.size()>k){
                s.erase(s.begin());
            }
           for(auto it=s.begin();it!=s.end();it++){
               ans[i].push_back(-1*(*it).second);
           }
        }
        for(int i=0;i<N;i++)
          {reverse(ans[i].begin(),ans[i].end());}
        return ans;
    }
    
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends