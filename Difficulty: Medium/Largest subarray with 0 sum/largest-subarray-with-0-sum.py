#Your task is to complete this function
 
class Solution:

    def maxLen(self, arr):
        # Create an empty hash map (dictionary)
        n = len(arr)
        hash_map = {}
        # Initialize result
        max_len = 0
        # Initialize sum of elements
        curr_sum = 0

        for i in range(n):
            # Add the current element to the sum
            curr_sum += arr[i]

            # Check if the current element is 0 and max_len is 0
            if arr[i] == 0 and max_len == 0:
                max_len = 1

            # If the cumulative sum is 0, update max_len
            if curr_sum == 0:
                max_len = i + 1

            # Check if the current sum has been seen before
            if curr_sum in hash_map:
                max_len = max(max_len, i - hash_map[curr_sum])
            else:
                # If not seen, put this sum in the dictionary
                hash_map[curr_sum] = i

        return max_len


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.maxLen(arr))
        print("~")

# } Driver Code Ends