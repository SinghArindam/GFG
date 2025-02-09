#User function Template for python3

class Solution:

    def findTwoElement(self, arr):
        ans = [0] * 2
        n = len(arr)
        for i in range(n):
            if arr[abs(arr[i]) - 1] > 0:
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]
            else:
                ans[0] = abs(arr[i])

        for i in range(n):
            if arr[i] > 0:
                ans[1] = i + 1
        return ans




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findTwoElement(arr)
        print(str(ans[0]) + " " + str(ans[1]))
        tc = tc - 1
        print("~")

# } Driver Code Ends