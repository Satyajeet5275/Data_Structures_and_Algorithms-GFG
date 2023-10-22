#User function Template for python3

class Solution:
    def numberOfPaths (self, m, n):
        Mod = 10**9 + 7
        result = 1

        # Calculate m+n-2 choose m-1
        for i in range(m-1):
            result = (result * (m + n - 2 - i)) % Mod
            result = (result * pow(i + 1, Mod - 2, Mod)) % Mod

        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

        

if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        M, N = map(int, input().split())
        ans = ob.numberOfPaths(M, N)
        print(ans)




# } Driver Code Ends