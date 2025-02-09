#User function Template for python3
class Solution:
    def longestCommonPrefix(self, arr):
        n = len(arr)
        if n == 1: return arr[0]
        res = ""
        include = False
        for i in range(len(arr[0])):
            include = True
            for j in range(n):
                if i >= len(arr[j]) or arr[0][i] != arr[j][i]:
                    include = False
                    break
            if include == False: break
            res += arr[0][i]

        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        arr = [x for x in input().strip().split(" ")]

        ob = Solution()
        ans = ob.longestCommonPrefix(arr)

        if not ans:
            print("\"\"")
        else:
            print(ans)

# } Driver Code Ends