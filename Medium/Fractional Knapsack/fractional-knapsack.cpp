//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
   static bool cmp(struct Item a,struct Item b) {
       double r1=(double)a.value/(double)a.weight;
       double r2=(double)b.value/(double)b.weight;
       if(r1<r2) return false;
       return true;
   }
   double fractionalKnapsack(int W, Item arr[], int n) {
       sort(arr,arr+n,cmp);
       double cost=0;
       for(int i=0;i<n;i++) {
           if(arr[i].weight<=W) {
               W-=arr[i].weight;
               cost+=arr[i].value;
           } else {
                   cost+=((double)arr[i].value/(double)arr[i].weight)*W;
                   break;
               }
       }
       return cost;
   }
        
};



//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends