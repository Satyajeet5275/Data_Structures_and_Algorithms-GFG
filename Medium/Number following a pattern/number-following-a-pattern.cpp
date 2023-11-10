//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        s=s+'I';
        int n=s.size();
        vector<int>v;
        int xx=0;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                v.push_back(xx);
                xx=0;
            }
            else{
                xx++;
            }
        }
        string ans="";
        char pre='1'+v[0];
        char pvs='1'+v[0];
        int idx=1;
        ans.push_back(pre);
        for(int i=0;i<n-1;i++){
            if(s[i]=='I'){
                pvs=pvs+v[idx++]+1;
                pre=pvs;
                ans.push_back(pvs);
            }
            else{
                pre=pre-1;
                ans.push_back(pre);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends