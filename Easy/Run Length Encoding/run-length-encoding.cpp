//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  int n=src.length();
  string ans;
  for(int i=0;i<n;){
      int freq=1;
      char ch=src[i];
      int j=i+1;
      while(j<n && src[j]==ch){
          freq++;
          j++;
      }
      ans+=ch+to_string(freq);
      i=j;
  }
  return ans;
}     
 
