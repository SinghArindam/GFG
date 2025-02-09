#User function Template for python3

class Solution:
    def findUnion(self, a, b):
        hs = set()
        for x in a:
            hs.add(x)
        for y in b:
            hs.add(y)
        return len(hs)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        a = [int(x) for x in input().strip().split()]
        b = [int(x) for x in input().strip().split()]
        ob = Solution()

        print(ob.findUnion(a, b))
        print("~")

# } Driver Code Ends