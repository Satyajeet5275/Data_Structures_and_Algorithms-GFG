//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
   bool isRotated(string str1, string str2)
    {
        // Your code here
        int n=str2.length()-1;
        if(str1.length()<=2){
            return false;
        }
        bool flag=true;
        for(int i=0;i<str1.length()-2;i++){
            if(((str1[0]==str2[n-1] && str1[1]==str2[n]) || (str2[0]==str1[n-1] && str2[1]==str1[n]))
            && ((str1[i+2]==str2[i]) || (str2[i+2]==str1[i]))){
                continue;
            }
            else{
                flag=false;
                break;
            }
        }
        return flag;
    }
    
};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends