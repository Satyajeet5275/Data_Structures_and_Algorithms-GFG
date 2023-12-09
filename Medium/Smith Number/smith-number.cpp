//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution {
//   public:
//     int sumPrimeFactor(int num){
//         int sum=0;
//         for(int i=2;i<num;i--){
//             while(num%i==0){
//                 sum+=i;
//                 num=num/i;
//             }
//         }
//         return sum;
//     }
//     int smithNum(int n) {
//         // code here
//         int sum=sumPrimeFactor(n);
//         if(sum==n)
//             return 1;
//         return 0;
//     }
// };

class Solution {
      
    public:
    int smithNum(int n) {
        vector<int> primeFactors;
        int num = n;
    
        for (int i = 2; i < n; i++) {
            while (num % i == 0) {
                primeFactors.push_back(i);
                num /= i;
            }
        }
    
        int number=n;
        int sum = 0;
            while (number) {
                int digit = number % 10;
                sum += digit;
                number /= 10;
            }
    
        int primeFactorSum = 0;
        for (int i = 0; i < primeFactors.size(); i++) {
            int currentFactor = primeFactors[i];
            while (currentFactor) {
                int digit = currentFactor % 10;
                primeFactorSum += digit;
                currentFactor /= 10;
            }
        }
    
        return sum == primeFactorSum;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends