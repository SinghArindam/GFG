#User function Template for python3
class Solution:
    # Function to find values in array equal to their indices
    def valueEqualToIndex(self, arr):
        ans = []  # create an empty list to store the values
        n = len(arr)
        # iterate through the array
        for i in range(n):
            # check if the value at index i is equal to its index + 1
            if arr[i] == i + 1:
                ans.append(arr[i])  # if true, add the value to the list
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.valueEqualToIndex(arr)
        if len(ans) == 0:
            print("Not Found")
        else:
            for x in ans:
                print(x, end=" ")
            print()
        tc -= 1
        print("~")

# } Driver Code Ends