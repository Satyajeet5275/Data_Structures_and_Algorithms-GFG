//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		   int nthPoint(int n){
            // Code here
            int n1=1,n2=2;
            int sum=0;
            if(n==1){
                return 1;
            }
            if(n==2){
                return 2;
            }
            else
            {
                for(int i=3;i<=n;i++){
                    sum=(n1+n2)%1000000007;
                    n1=n2;
                    n2=sum;
                }
            }
            return sum%1000000007;
        }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends