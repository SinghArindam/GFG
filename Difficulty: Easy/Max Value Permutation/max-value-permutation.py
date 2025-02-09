#User function Template for python3

class Solution:
    def maxValue(self, arr):

        n = len(arr)
        arr.sort()  #sorting the array

        mod = 1000000007  #taking modulo for large values

        s = 0  #variable to store the sum

        for i in range(n):
            s += arr[
                i] * i
            s = s % mod

        return s % mod
      



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        # k = int(input())
        ob = Solution()
        print(ob.maxValue(A))
        print("~")

# } Driver Code Ends