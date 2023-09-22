//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int s = 0;
        int e = n-1;
        int mid = (s+e)/2;
        while(s < e){
            if(arr[mid] >= x){
                e = mid;
            }
            else{
                 s = mid + 1;
            }
          
            mid = (s + e)/2;
        }
        
        int f = n-1;
        if(arr[s] == x ){
            for(int i=s; i<n; i++){
                if(arr[i] != x){
                   f = i-1; 
                   break;
                }
            }
            return {s,f};
        }
        else{
            return {-1,-1};
        }
    }


};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends