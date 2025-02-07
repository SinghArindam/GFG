#User function Template for python3


class Solution:

    def kthSmallest(self, arr, k):
        max_element = max(arr)
        n = len(arr)

        # Create an array to store the frequency of each element in the input array
        freq = [0] * (max_element + 1)
        for i in range(n):
            freq[arr[i]] += 1

        # Keep track of the cumulative frequency of elements in the input array
        count = 0
        for i in range(max_element + 1):
            if freq[i] != 0:
                count += freq[i]
                if count >= k:
                    # If we have seen k or more elements, return the current element
                    return i
        return -1
        
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__':
    import random
    t = int(input())
    for tcs in range(t):
        # n = int(input())
        arr = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.kthSmallest(arr, k))
        print("~")
# } Driver Code Ends