//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string str)
	{
	    // code here 
	    unordered_map<char, int> mp;
	    unordered_map<int, int> mp2;
	    for(auto &c: str)mp[c]++;
	    for(auto &it: mp)
	    {
	        mp2[it.second]++;
	    }
	    
	    if(mp2.size()==1)return true;
	    if(mp2.size()>2)return false;
	    pair<int, int> a, b;
	    int i=0;
	    for(auto &it: mp2)
	    {
	        if(!i)a=it;
	        else b=it;
	        i++;
	    }
	    
	    if(a.first>b.first)swap(a,b);
	    
	    if(a.first==1)return true;
	    if(b.second!=1)return false;
	    
	    return b.first-a.first==1;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends