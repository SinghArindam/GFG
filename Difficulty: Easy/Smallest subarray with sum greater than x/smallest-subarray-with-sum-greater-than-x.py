class Solution:

    def smallestSubWithSum(self, x, arr):
        n = len(arr)  # Get the size of the array
        curr_sum = 0  # Initialize the current sum
        min_len = n + 1  # Initialize the minimum length to a large value
        start = 0  # Initialize the start pointer
        end = 0  # Initialize the end pointer

        # Traverse the array
        while end < n:
            # Expand the window by adding elements to curr_sum until it exceeds x
            while curr_sum <= x and end < n:
                curr_sum += arr[end]
                end += 1

            # Shrink the window from the left while curr_sum is greater than x
            while curr_sum > x and start < n:
                # Update the minimum length if the current window is smaller
                if end - start < min_len:
                    min_len = end - start

                # Remove elements from the start of the window
                curr_sum -= arr[start]
                start += 1

        # If no valid subarray is found, return 0
        if min_len > n:
            return 0
        return min_len
        



#{ 
 # Driver Code Starts
def main():

    T = int(input())

    while (T > 0):
        x = int(input())
        a = [int(x) for x in input().strip().split()]
        print(Solution().smallestSubWithSum(x, a))

        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends