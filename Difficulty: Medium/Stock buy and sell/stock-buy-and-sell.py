#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function template for Python

class Solution:

    def stockBuySell(self, arr):
        # Initialize profit to 0. This will hold the total profit.
        profit = 0

        # Loop through the arr array starting from the second element (index 1)
        for i in range(1, len(arr)):
            # Check if the price today (arr[i]) is greater than the price yesterday (arr[i-1]).
            # This means there's an opportunity for profit, as buying yesterday and selling today would yield profit.
            if arr[i - 1] < arr[i]:
                # Add the difference (profit) to the total profit.
                profit += arr[i] - arr[i - 1]

        # Return the accumulated profit after processing all days.
        return profit

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.stockBuySell(arr)
        print(res)
        print("~")
        t -= 1


# } Driver Code Ends